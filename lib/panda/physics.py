from common import *
from base import Definition
from obj import Object
from branch import Branch
from output import FileOutput

class PhysicsObject(Definition, Object):
    """
    Physics object definition. Definition file syntax:
    
    [Name(>Parent)(:SINGLE)]
    <variable definitions>
    <function definitions>
    """

    _known_objects = []

    @staticmethod
    def get(name):
        try:
            return next(o for o in PhysicsObject._known_objects if o.name == name)
        except StopIteration:
            raise KeyError('PhysicsObject.get({name})'.format(name = name))

    def __init__(self, line, source):
        """
        Argument: re match object
        """

        Definition.__init__(self, line, '\\[([A-Z][a-zA-Z0-9]+)(>[A-Z][a-zA-Z0-9]+|)(\\:SINGLE|)\\] *$')
        PhysicsObject._known_objects.append(self)

        # is this a singlet?
        if self.matches.group(3) == ':SINGLE':
            self.parent = 'Singlet'
            self._singlet = True
        else:
            self.parent = 'ContainerElement'
            self._singlet = False

        # if >parent is present, update the parent class name
        if self.matches.group(2):
            self.parent = self.matches.group(2)[1:]
            self._singlet = None

        Object.__init__(self, self.matches.group(1), source)

    def is_singlet(self):
        if self._singlet is None:
            return PhysicsObject.get(self.parent).is_singlet()
        else:
            return self._singlet

    def generate_header(self):
        """
        Write a header file.
        """

        inheritance = [self]
        while True:
            try:
                inheritance.insert(0, PhysicsObject.get(inheritance[0].parent))
            except KeyError:
                break

        header = FileOutput('{PACKDIR}/Objects/interface/{name}.h'.format(PACKDIR = PACKDIR, name = self.name))
        header.writeline('#ifndef {PACKAGE}_Objects_{name}_h'.format(PACKAGE = PACKAGE, name = self.name))
        header.writeline('#define {PACKAGE}_Objects_{name}_h'.format(PACKAGE = PACKAGE, name = self.name))
        header.writeline('#include "Constants.h"')

        included = ['#include "{name}.h"'.format(name = self.name)]
        if self.parent == 'ContainerElement':
            header.writeline('#include "../../Framework/interface/ContainerElement.h"')
        elif self.parent == 'Singlet':
            header.writeline('#include "../../Framework/interface/Singlet.h"')
        else:
            stmt = '#include "{parent}.h"'.format(parent = self.parent)
            if stmt not in included:
                header.writeline(stmt)
                included.append(stmt)

        header.writeline('#include "../../Framework/interface/Container.h"')
        header.writeline('#include "../../Framework/interface/Ref.h"')
        header.writeline('#include "../../Framework/interface/RefVector.h"')

        for include in self.includes:
            if include.code not in included:
                include.write(header)
                included.append(include.code)

        for branch in self.branches:
            if hasattr(branch, 'refname'): # is a RefBranch
                stmt = '#include "{obj}.h"'.format(obj = branch.objname)
                if stmt not in included:
                    header.writeline(stmt)
                    included.append(stmt)

        header.newline()
        header.writeline('namespace {NAMESPACE} {{'.format(NAMESPACE = NAMESPACE))
        header.newline()
        header.indent += 1

        header.writeline('class {name} : public {parent} {{'.format(name = self.name, parent = self.parent))
        header.writeline('public:')
        header.indent += 1
        
        if not self.is_singlet():
            header.writeline('struct datastore : public {parent}::datastore {{'.format(parent = self.parent))
            header.indent += 1

            header.writeline('datastore() : {parent}::datastore() {{}}'.format(parent = self.parent))
            header.writeline('~datastore() { deallocate(); }')

            newline = False
            for ancestor in inheritance:
                if len(ancestor.branches) == 0:
                    continue

                if not newline:
                    header.newline()
                    newline = True

                if ancestor != self:
                    header.writeline('/* {name}'.format(name = ancestor.name))

                for branch in ancestor.branches:
                    branch.write_decl(header, context = 'datastore')

                if ancestor != self:
                    header.writeline('*/')

            header.newline()
            header.writeline('void allocate(UInt_t n) override;')
            header.writeline('void deallocate() override;')
            header.writeline('void setStatus(TTree&, TString const&, utils::BranchList const& = {"*"}) override;')
            header.writeline('void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;')
            header.writeline('void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;')
            header.writeline('void resetAddress(TTree&, TString const&) override;')
            header.writeline('void resizeVectors_(UInt_t) override;')

            header.indent -= 1
            header.writeline('};')
            header.newline()

            header.writeline('typedef {parent} base_type;'.format(parent = self.parent))
            header.writeline('typedef Array<{name}> array_type;'.format(name = self.name, parent = self.parent))
            header.writeline('typedef Collection<{name}> collection_type;'.format(name = self.name, parent = self.parent))
            header.newline()

        # "boilerplate" functions (default ctor for non-SINGLE objects are pretty nontrivial though)
        header.writeline('{name}(char const* name = "");'.format(name = self.name)) # default constructor
        header.writeline('{name}({name} const&);'.format(name = self.name)) # copy constructor

        # standard constructors and specific functions
        if not self.is_singlet():
            # whereas elements of collections are constructed from an array and an index
            header.writeline('{name}(datastore&, UInt_t idx);'.format(name = self.name))

        header.writeline('~{name}();'.format(name = self.name)) # destructor
        header.writeline('{name}& operator=({name} const&);'.format(name = self.name)) # assignment operator

        header.newline()

        # I/O with default name
        header.writeline('void setStatus(TTree&, utils::BranchList const& = {"*"}) override;')
        header.writeline('UInt_t setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;')
        header.writeline('UInt_t book(TTree&, utils::BranchList const& = {"*"}) override;')
        header.writeline('void releaseTree(TTree&) override;')

        header.newline()
        header.writeline('void init() override;')

        if len(self.constants) != 0:
            header.newline()
            for constant in self.constants:
                constant.write_decl(header, context = 'class')

        if len(self.functions) != 0:
            header.newline()
            for function in self.functions:
                function.write_decl(header, context = 'class')

        if self.is_singlet():
            context = 'Singlet'
        else:
            context = 'ContainerElement'

        newline = False
        for ancestor in inheritance:
            if len(ancestor.branches) == 0:
                continue

            if not newline:
                header.newline()
                newline = True

            if ancestor != self:
                header.writeline('/* {name}'.format(name = ancestor.name))

            for branch in ancestor.branches:
                branch.write_decl(header, context = context)

            if ancestor != self:
                header.writeline('*/')

        header.newline()
        header.write_custom_block('{name}.h.classdef'.format(name = self.name))

        if not self.is_singlet():
            header.newline()
            header.writeline('void destructor() override;')
            header.newline()
            header.indent -= 1
            header.writeline('protected:')
            header.indent += 1
            header.writeline('{name}(ArrayBase*);'.format(name = self.name))

        header.indent -= 1

        header.writeline('};')

        header.newline()

        if not self.is_singlet():
            header.writeline('typedef {name}::array_type {name}Array;'.format(name = self.name))
            header.writeline('typedef {name}::collection_type {name}Collection;'.format(name = self.name))
            header.writeline('typedef Ref<{name}> {name}Ref;'.format(name = self.name))
            header.writeline('typedef RefVector<{name}> {name}RefVector;'.format(name = self.name))
            header.newline()

        header.write_custom_block('{name}.h.global'.format(name = self.name))
        header.newline()

        header.indent -= 1
        header.writeline('}')
        header.newline()

        header.writeline('#endif')
        header.close()

    def _write_method(self, out, context, methodspec, nestedcls = ''):
        """
        Util function to write class methods with a common pattern.
        """

        fname, rettype, arguments, generator, retexpr = methodspec[:5]
        if len(methodspec) == 6:
            pre_lines = methodspec[5]
        else:
            pre_lines = []

        out.writeline(rettype)
        signature = []
        for arg in arguments:
            s = '{0} {1}'.format(*arg)
            if len(arg) == 3: # has default
                s += '/* = {0}*/'.format(arg[2])
                
            signature.append(s)

        args = ', '.join(arg[1] for arg in arguments)

        if nestedcls:
            name = self.name + '::' + nestedcls
            parent = self.parent + '::' + nestedcls
        else:
            name = self.name
            parent = self.parent

        out.writeline('{NAMESPACE}::{name}::{fname}({signature})'.format(NAMESPACE = NAMESPACE, name = name, fname = fname, signature = ', '.join(signature)))
        out.writeline('{')
        out.indent += 1
        out.writeline('{parent}::{fname}({args});'.format(parent = parent, fname = fname, args = args))

        if len(pre_lines) != 0:
            out.newline()
            for line in pre_lines:
                out.writeline(line)

        if len(self.branches) != 0:
            out.newline()
            for branch in self.branches:
                getattr(branch, generator)(out, context = context)

        if retexpr:
            out.newline()
            out.writeline('return {expr};'.format(expr = retexpr))

        out.indent -= 1
        out.writeline('}')

    def generate_source(self):
        """
        Write the .cc file.
        """

        subst = {'NAMESPACE': NAMESPACE, 'name': self.name, 'parent': self.parent}

        src = FileOutput('{PACKDIR}/Objects/src/{name}.cc'.format(PACKDIR = PACKDIR, **subst))
        src.writeline('#include "../interface/{name}.h"'.format(**subst))

        if len(self.constants) != 0:
            src.newline()
            for constant in self.constants:
                constant.write_def(src)

        if self.is_singlet():
            src.newline()

            src.writeline('{NAMESPACE}::{name}::{name}(char const* _name/* = ""*/) :'.format(**subst))
            src.indent += 1
            initializers = ['{parent}(_name)'.format(**subst)]
            for branch in self.branches:
                branch.init_default(initializers, context = 'Singlet')
            src.writelines(initializers, ',')
            src.indent -= 1
            src.writeline('{')
            src.indent += 1
            for branch in self.branches:
                branch.write_default_ctor(src, context = 'Singlet')
            src.indent -= 1
            src.writeline('}')
            src.newline()

            src.writeline('{NAMESPACE}::{name}::{name}({name} const& _src) :'.format(**subst))
            src.indent += 1
            initializers = ['{parent}(_src.name_)'.format(**subst)]
            for branch in self.branches:
                branch.init_copy(initializers, context = 'Singlet')
            src.writelines(initializers, ',')
            src.indent -= 1
            src.writeline('{')
            src.indent += 1
            for branch in self.branches:
                branch.write_copy_ctor(src, context = 'Singlet')
            src.indent -= 1
            src.writeline('}')
            src.newline()

            src.writeline('{NAMESPACE}::{name}::~{name}()'.format(**subst))
            src.writeline('{')
            src.writeline('}')

            methods = [
                ('operator=', '{NAMESPACE}::{name}&'.format(**subst), [('{name} const&'.format(**subst), '_src')], 'write_assign', '*this'),
                ('setStatus', 'void', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_set_status', None),
                ('setAddress', 'UInt_t', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}'), ('Bool_t', '_setStatus', 'kTRUE')], 'write_set_address', '-1'),
                ('book', 'UInt_t', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_book', '-1'),
                ('releaseTree', 'void', [('TTree&', '_tree')], 'write_reset_address', None),
                ('init', 'void', [], 'write_init', None)
            ]

            for method in methods:
                src.newline()
                self._write_method(src, 'Singlet', method)

        #if self.is_singlet():
        else:
            size_lines = ['TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));']
            methods = [
                ('allocate', 'void', [('UInt_t', '_nmax')], 'write_allocate', None),
                ('deallocate', 'void', [], 'write_deallocate', None),
                ('setStatus', 'void', [('TTree&', '_tree'), ('TString const&', '_name'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_set_status', None),
                ('setAddress', 'void', [('TTree&', '_tree'), ('TString const&', '_name'), ('utils::BranchList const&', '_branches', '{"*"}'), ('Bool_t', '_setStatus', 'kTRUE')], 'write_set_address', None),
                ('book', 'void', [('TTree&', '_tree'), ('TString const&', '_name'), ('utils::BranchList const&', '_branches', '{"*"}'), ('Bool_t', '_dynamic', 'kTRUE')], 'write_book', None, size_lines),
                ('resetAddress', 'void', [('TTree&', '_tree'), ('TString const&', '_name')], 'write_reset_address', None),
                ('resizeVectors_', 'void', [('UInt_t', '_size')], 'write_resize_vectors', None)
            ]

            for method in methods:
                src.newline()
                self._write_method(src, 'datastore', method, nestedcls = 'datastore')

            src.newline()
            src.writeline('{NAMESPACE}::{name}::{name}(char const* _name/* = ""*/) :'.format(**subst))
            src.indent += 1
            initializers = ['{parent}(new {name}Array(1, _name))'.format(**subst)]
            for branch in self.branches:
                branch.init_default(initializers, context = 'ContainerElement')
            src.writelines(initializers, ',')
            src.indent -= 1
            src.writeline('{')
            src.indent += 1
            for branch in self.branches:
                branch.write_default_ctor(src, context = 'ContainerElement')
            src.indent -= 1
            src.writeline('}')

            src.newline()
            src.writeline('{NAMESPACE}::{name}::{name}(datastore& _data, UInt_t _idx) :'.format(**subst))
            src.indent += 1
            initializers = ['{parent}(_data, _idx)'.format(**subst)]
            for branch in self.branches:
                branch.init_standard(initializers, context = 'ContainerElement')
            src.writelines(initializers, ',')
            src.indent -= 1
            src.writeline('{')
            src.indent += 1
            for branch in self.branches:
                branch.write_standard_ctor(src, context = 'ContainerElement')
            src.indent -= 1
            src.writeline('}')

            src.newline()
            src.writeline('{NAMESPACE}::{name}::{name}({name} const& _src) :'.format(**subst))
            src.indent += 1
            initializers = ['{parent}(new {name}Array(1, gStore.getName(&_src)))'.format(**subst)]
            for branch in self.branches:
                branch.init_copy(initializers, context = 'ContainerElement')
            src.writelines(initializers, ',')
            src.indent -= 1
            src.writeline('{')
            src.indent += 1
            src.writeline('{parent}::operator=(_src);'.format(**subst))
            if len(self.branches) != 0:
                src.newline()
                for branch in self.branches:
                    branch.write_copy_ctor(src, context = 'ContainerElement')
            src.indent -= 1
            src.writeline('}')

            src.newline()
            src.writeline('{NAMESPACE}::{name}::{name}(ArrayBase* _array) :'.format(**subst))
            src.indent += 1
            initializers = ['{parent}(_array)'.format(**subst)]
            for branch in self.branches:
                branch.init_default(initializers, context = 'ContainerElement')
            src.writelines(initializers, ',')
            src.indent -= 1
            src.writeline('{')
            src.indent += 1
            for branch in self.branches:
                branch.write_default_ctor(src, context = 'ContainerElement')
            src.indent -= 1
            src.writeline('}')

            src.newline()
            src.writeline('{NAMESPACE}::{name}::~{name}()'.format(**subst))
            src.writeline('{')
            src.indent += 1
            src.writeline('destructor();')
            src.writeline('gStore.free(this);')
            src.indent -= 1
            src.writeline('}')

            src.newline()
            src.writeline('void')
            src.writeline('{NAMESPACE}::{name}::destructor()'.format(**subst))
            src.writeline('{')
            src.indent += 1
            src.write_custom_block('{name}.cc.destructor'.format(**subst))
            src.newline()
            src.writeline('{parent}::destructor();'.format(**subst))
            src.indent -= 1
            src.writeline('}')


            name_line = 'TString name(gStore.getName(this));'
            methods = [
                ('operator=', '{NAMESPACE}::{name}&'.format(**subst), [('{name} const&'.format(**subst), '_src')], 'write_assign', '*this'),
                ('setStatus', 'void', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_set_status', None, [name_line]),
                ('setAddress', 'UInt_t', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}'), ('Bool_t', '_setStatus', 'kTRUE')], 'write_set_address', '-1', [name_line]),
                ('book', 'UInt_t', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_book', '-1', [name_line]),
                ('releaseTree', 'void', [('TTree&', '_tree')], 'write_reset_address', None, [name_line]),
                ('init', 'void', [], 'write_init', None)
            ]

            for method in methods:
                src.newline()
                self._write_method(src, 'ContainerElement', method)

        if len(self.functions):
            src.newline()
            for function in self.functions:
                function.write_def(src, context = self.name)

        src.newline()
        src.write_custom_block('{name}.cc.global'.format(**subst))

        src.close()
