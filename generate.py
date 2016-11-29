#!/usr/bin/env python

import os
import re

NAMESPACE = 'panda'
PACKDIR = os.path.realpath(os.path.dirname(__file__))
PACKAGE = os.path.basename(PACKDIR)

PRESERVE_CUSTOM = True

class Definition(object):
    """
    Base class for all objects reading from the definitions file.
    """

    class NoMatch(Exception):
        pass

    def __init__(self, line, pattern):
        matches = re.match(pattern, line)
        if matches is None:
            raise Definition.NoMatch()

        self.matches = matches


class OneLiner(Definition):
    """
    Single-liner C++ code to be directly written into target code.
    """

    def __init__(self, line, pattern):
        Definition.__init__(self, line, pattern)
        self.code = line.strip()

    def write(self, out):
        out.writeline(self.matches.group(0))


class Include(OneLiner):
    """
    C++ include lines.
    """

    def __init__(self, line):
        OneLiner.__init__(self, line, '#include +[^ ]+$')


class Typedef(OneLiner):
    """
    C++ typedef lines.
    """
    
    def __init__(self, line):
        OneLiner.__init__(self, line, 'typedef +[^ ]+ +[^ ]+$')


class Constant(Definition):
    """
    C++ const lines.
    """

    def __init__(self, line):
        Definition.__init__(self, line, '((?:static +|)(?:const +[^ ]+|[^ ]+ +const) +[a-zA-Z0-9_]+(?:\[[^\]]+\])*)(.*);')
        self.decl = self.matches.group(1)
        self.value = self.matches.group(2)

    def write_decl(self, out, context):
        if context == 'class':
            out.writeline('{decl};'.format(decl = self.decl))
        elif context == 'global':
            out.writeline('{decl}{value};'.format(decl = self.decl, value = self.value))

    def write_def(self, out):
        out.writeline('/*static*/')
        out.writeline('{decl}{value};'.format(decl = self.decl.replace('static ', ''), value = self.value))


class AssertDef(Definition):
    """
    Compile-time assertions.
    Takes any C++ expression that evaluates to a boolean with syntax
    ASSERT <expr>
    """

    @staticmethod
    def write(assertions, out):
        # write the assertions as an enum of values sizeof(char[N])
        # if the condition is false, N is negative -> compile error.
        asserts = []
        for ia, assertion in enumerate(assertions):
            asserts.append('AST{i} = sizeof(char[({expr}) ? 1 : -1])'.format(i = ia, expr = assertion.matches.group(1)))

        enum = EnumDef('enum Assertions {', asserts)
        enum.write_decl(out, names = False)

    def __init__(self, line):
        Definition.__init__(self, line, 'ASSERT +(.+)')


class EnumDef(Definition):
    """
    C++ enum definition.
    """

    def __init__(self, line, source):
        Definition.__init__(self, line, 'enum *([^ ]+) *\\{')

        self.name = self.matches.group(1)

        if type(source) is list:
            # a list is already given
            self.elements = source

        else:
            # otherwise parse the source text
            self.elements = []
    
            while True:
                line = source.readline()
                if line == '':
                    break
    
                if line.strip().startswith('}'):
                    break
    
                for elem in line.strip().split(','):
                    elem = elem.strip()
                    if elem:
                        self.elements.append(elem)

        # last entry is always n{name}s (e.g. enum Trigger -> nTriggers)
        self.elements.append('n{name}s'.format(name = self.name))

    def write_decl(self, out, names = True):
        out.writeline('enum ' + self.name + ' {')
        out.indent += 1
        out.writelines(self.elements, ',')
        out.indent -= 1
        out.writeline('};')

        if names:
            out.newline()
            out.writeline('extern TString {name}Name[{size}];'.format(name = self.name, size = self.elements[-1]))
            out.writeline('TTree* make{name}Tree();'.format(name = self.name))

    def write_def(self, out):
        enum_names = []
        for elem in self.elements[:-1]:
            enum_names.append('"{elem}"'.format(elem = elem))

        out.writeline('TString {NAMESPACE}::{name}Name[] = {{'.format(NAMESPACE = NAMESPACE, name = self.name))
        out.indent += 1
        out.writelines(enum_names, ',')
        out.indent -= 1
        out.writeline('};')

        out.newline()
        out.writeline('TTree*')
        out.writeline('{NAMESPACE}::make{name}Tree()'.format(NAMESPACE = NAMESPACE, name = self.name))
        out.writeline('{')
        out.indent += 1
        out.writeline('auto* tree(new TTree("{name}", "{name}"));'.format(name = self.name))
        out.writeline('char name[1024];')
        out.writeline('tree->Branch("name", name, "name/C");')
        out.writeline('for (auto&& n : {name}Name) {{'.format(name = self.name))
        out.indent += 1
        out.writeline('std::strcpy(name, n.Data());')
        out.writeline('tree->Fill();')
        out.indent -= 1
        out.writeline('}')
        out.writeline('tree->ResetBranchAddresses();')
        out.writeline('return tree;')
        out.indent -= 1
        out.writeline('}')


class BranchDef(Definition):
    """
    Single branch definition. Definition file syntax:
    <name>([size])/<type>( = <init>)
    where <type> can be an object name or ROOT leaf type symbol.
    """

    TYPE_MAP = {'C': 'Text_t const*', 'B': 'Char_t', 'b': 'UChar_t', 'S': 'Short_t', 's': 'UShort_t',
        'I': 'Int_t', 'i': 'UInt_t', 'L': 'Long64_t', 'l': 'ULong64_t', 'F': 'Float_t', 'D': 'Double_t', 'O': 'Bool_t'}

    def __init__(self, line):
        Definition.__init__(self, line, '([a-zA-Z_][a-zA-Z0-9_]*)(|\\[.+\\])/([^ ]+)(?:| += +(.*))$')

        self.name = self.matches.group(1)
        # is this an array branch?
        arrdef = self.matches.group(2)
        if arrdef:
            self.arrdef = arrdef.strip('[]').split('][')
        else:
            self.arrdef = []
        self.type = self.matches.group(3)
        self.init = self.matches.group(4) # used in decl
        if self.init is None:
            self.init = ''

        # initializer: used in init()
        if self.is_simple():
            if self.init:
                init = self.init
            elif self.type == 'O':
                init = 'false'
            elif self.type in 'FD':
                init = '0.'
            else:
                init = '0'
        
            if self.is_array():
                self.initializer = ''
                arr = self.name
                for iarr in range(len(self.arrdef)):
                    self.initializer += 'for (auto& p{iarr} : {arr}) '.format(iarr = iarr, arr = arr)
                    arr = 'p{iarr}'.format(iarr = iarr)
                self.initializer += 'p{iarr} = {init};'.format(iarr = iarr, init = init)
            else:
                self.initializer = '{name} = {init};'.format(name = self.name, init = init)

        else:
            self.initializer = '/*INITIALIZE {name}*/'.format(name = self.name)

    def is_simple(self):
        return len(self.type) == 1 and self.type in 'CBbSsIiLlFDO'

    def is_array(self):
        # True if the branch itself is an array
        return len(self.arrdef) != 0

    def arrdef_text(self, begin = None, end = None):
        return ''.join('[%s]' % a for a in self.arrdef[begin:end])

    def typename(self):
        try:
            return BranchDef.TYPE_MAP[self.type]
        except KeyError:# object type
            return self.type

    def write_decl(self, out, context):
        if context == 'datastore':
            if self.is_array():
                out.writeline('{type} (*{name}){arrdef}{{0}};'.format(type = self.typename(), name = self.name, arrdef = self.arrdef_text()))
            else:
                out.writeline('{type}* {name}{{0}};'.format(type = self.typename(), name = self.name, arrdef = self.arrdef_text()))
        elif context == 'Singlet' or context == 'TreeEntry':
            out.writeline('{type} {name}{arrdef}{{{init}}};'.format(type = self.typename(), name = self.name, arrdef = self.arrdef_text(), init = self.init))
        elif context == 'ContainerElement':
            if self.is_array():
                out.writeline('{type} (&{name}){arrdef};'.format(type = self.typename(), name = self.name, arrdef = self.arrdef_text()))
            else:
                out.writeline('{type}& {name};'.format(type = self.typename(), name = self.name))

    def write_allocate(self, out, context):
        # context must be datastore
        out.writeline('{name} = new {type}[nmax_]{arrdef};'.format(name = self.name, type = self.typename(), arrdef = self.arrdef_text()))

    def write_deallocate(self, out, context):
        # context must be datastore
        out.writeline('delete [] {name};'.format(name = self.name))
        out.writeline('{name} = 0;'.format(name = self.name))

    def write_set_status(self, out, context):
        if context == 'datastore':
            namevar = '_name'
        elif context == 'Singlet':
            namevar = 'name_'
        elif context == 'ContainerElement':
            namevar = 'name'
        elif context == 'TreeEntry':
            namevar = '""'

        out.writeline('utils::setStatus(_tree, {namevar}, "{name}", _status, _branches);'.format(namevar = namevar, name = self.name))

    def write_set_address(self, out, context):
        if context == 'datastore':
            namevar = '_name'
        elif context == 'Singlet':
            namevar = 'name_'
        elif context == 'ContainerElement':
            namevar = 'name'
        elif context == 'TreeEntry':
            namevar = '""'

        if context == 'datastore' or self.is_array():
            ptr = self.name
        else:
            ptr = '&' + self.name

        out.writeline('utils::setAddress(_tree, {namevar}, "{name}", {ptr}, _branches, _setStatus);'.format(namevar = namevar, name = self.name, ptr = ptr))

    def write_book(self, out, context):
        size_str = '"{arrdef}"'.format(arrdef = self.arrdef_text())

        if context == 'datastore':
            namevar = '_name'
            if self.is_array():
                size_str = 'size + ' + size_str
            else:
                size_str = 'size'
        elif context == 'Singlet':
            namevar = 'name_'
        elif context == 'ContainerElement':
            namevar = 'name'
        elif context == 'TreeEntry':
            namevar = '""'

        if context == 'datastore' or self.is_array():
            ptr = self.name
        else:
            ptr = '&' + self.name

        out.writeline('utils::book(_tree, {namevar}, "{name}", {size}, \'{type}\', {ptr}, _branches);'.format(namevar = namevar, name = self.name, size = size_str, type = self.type, ptr = ptr))

    def write_reset_address(self, out, context):
        if context == 'datastore':
            namevar = '_name'
        elif context == 'Singlet':
            namevar = 'name_'
        elif context == 'ContainerElement':
            namevar = 'name'
        elif context == 'TreeEntry':
            namevar = '""'

        out.writeline('utils::resetAddress(_tree, {namevar}, "{name}");'.format(namevar = namevar, name = self.name))

    def init_default(self, lines, context):
        if context == 'ContainerElement':
            lines.append('{name}(gStore.getData(this).{name}[0])'.format(name = self.name))

    def init_standard(self, lines, context):
        if context == 'ContainerElement':
            lines.append('{name}(_data.{name}[_idx])'.format(name = self.name))

    def init_copy(self, lines, context):
        if context == 'Singlet' or context == 'TreeEntry':
            if not self.is_array():
                lines.append('{name}(_src.{name})'.format(name = self.name))
        elif context == 'ContainerElement':
            lines.append('{name}(gStore.getData(this).{name}[0])'.format(name = self.name))

    def write_default_ctor(self, out, context):
        pass

    def write_standard_ctor(self, out, context):
        pass

    def write_copy_ctor(self, out, context):
        pass

    def write_assign(self, out, context):
        if self.is_array():
            size = ' * '.join(self.arrdef)
            'std::memcpy({name}, _src.{name}, sizeof({type}) * {size});'.format(name = self.name, type = self.typename(), size = size)
        else:
            out.writeline('{name} = _src.{name};'.format(name = self.name))

    def write_init(self, out, context):
        out.writeline(self.initializer)


class RefBranchDef(BranchDef):
    """
    Reference definition. Definition file syntax:
    <name>/<type>*
    References are written as unsigned integers to the trees.
    """

    def __init__(self, line):
        Definition.__init__(self, line, '([a-zA-Z_][a-zA-Z0-9_]*)(|\\[.+\\])/([^ ]+)\*$')
        self.refname = self.matches.group(1)
        arrdef = self.matches.group(2)
        self.objname = self.matches.group(3)
        try:
            objdef = PhysicsObjectDef.get(self.objname)
        except KeyError:
            raise Definition.NoMatch

        if objdef.coltype() == PhysicsObjectDef.SINGLE:
            raise RuntimeError('Cannot create reference to single object ' + objdef.name)

        # create a branch for the index with name {name}_
        BranchDef.__init__(self, '{name}_{arrdef}/i = -1'.format(name = self.refname, arrdef = arrdef, type = self.objname))

    def write_decl(self, out, context):
        if context == 'datastore':
            BranchDef.write_decl(self, out, context)
        else:
            if context == 'Singlet':
                out.indent -= 1
                out.writeline('protected:')
                out.indent += 1
                BranchDef.write_decl(self, out, context)
                out.indent -= 1
                out.writeline('public:')
                out.indent += 1

            if self.is_array():
                # Ref does not have a default constructor -> need to declare as a pointer and do allocate-deallocate
                out.writeline('Ref<{type}> {name}{arrdef}{{}};'.format(type = self.objname, name = self.refname, arrdef = self.arrdef_text()))
            else:
                out.writeline('Ref<{type}> {name};'.format(type = self.objname, name = self.refname))

    def write_set_address(self, out, context):
        if context == 'ContainerElement':
            subscript = ''.join('[0]' for a in self.arrdef)
            out.writeline('utils::setAddress(_tree, name, "{name}", &{refname}{subscript}.idx(), _branches, true);'.format(name = self.name, refname = self.refname, subscript = subscript))
        else:
            BranchDef.write_set_address(self, out, context)

    def write_book(self, out, context):
        if context == 'ContainerElement':
            subscript = ''.join('[0]' for a in self.arrdef)
            out.writeline('utils::book(_tree, name, "{name}", "{arrdef}", \'{type}\', &{refname}{subscript}.idx(), _branches);'.format(name = self.name, arrdef = self.arrdef_text(), type = self.type, refname = self.refname, subscript = subscript))
        else:
            BranchDef.write_book(self, out, context)

    def write_reset_address(self, out, context):
        if context == 'ContainerElement':
            out.writeline('utils::resetAddress(_tree, name, "{name}");'.format(name = self.name))
        else:
            BranchDef.write_reset_address(self, out, context)

    def init_default(self, lines, context):
        if self.is_array():
            return

        if context == 'Singlet':
            lines.append('{name}({name}_)'.format(name = self.refname))
        elif context == 'ContainerElement':
            lines.append('{name}(gStore.getData(this).{name}_[0])'.format(name = self.refname))

    def init_standard(self, lines, context):
        if self.is_array():
            return

        if context == 'ContainerElement':
            lines.append('{name}(_data.{name}_[_idx])'.format(name = self.refname))

    def init_copy(self, lines, context):
        if self.is_array(): 
            return

        if context == 'Singlet' or context == 'TreeEntry':
            BranchDef.init_copy(lines, context)
            lines.append('{name}({name}_)'.format(name = self.refname))
        elif context == 'ContainerElement':
            lines.append('{name}(gStore.getData(this).{name}_[0])'.format(name = self.refname))

    def write_default_ctor(self, out, context):
        if not self.is_array():
            return

        if context == 'Singlet':
            out.writeline('UInt_t (&{refname}Indices){arrdef}({name});'.format(refname = self.refname, arrdef = self.arrdef_text(), name = self.name))
        else:
            out.writeline('UInt_t (&{refname}Indices){arrdef}(gStore.getData(this).{name}[0]);'.format(refname = self.refname, arrdef = self.arrdef_text(), name = self.name))

        self._write_ref_set(out)

    def write_standard_ctor(self, out, context):
        if not self.is_array():
            return

        out.writeline('UInt_t (&{refname}Indices){arrdef}(_data.{name}[_idx]);'.format(refname = self.refname, arrdef = self.arrdef_text(), name = self.name))

        self._write_ref_set(out)

    def write_copy_ctor(self, out, context):
        if not self.is_array():
            return

        if context == 'Singlet':
            out.writeline('UInt_t (&{refname}Indices){arrdef}({name});'.format(refname = self.refname, arrdef = self.arrdef_text(), name = self.name))
        else:
            out.writeline('UInt_t (&{refname}Indices){arrdef}(gStore.getData(this).{name}[0]);'.format(refname = self.refname, arrdef = self.arrdef_text(), name = self.name))

        self._write_ref_set(out)
        # copy is performed in write_assign

    def _write_ref_set(self, out, copy = False):
        subscript = ''
        array = self.refname + 'Indices'            
        for depth in range(len(self.arrdef)):
            out.writeline('for (UInt_t i{depth}(0); i{depth} != sizeof({array}); ++i{depth}) {{'.format(depth = depth, array = array))
            subscript += '[i{depth}]'.format(depth = depth)
            newarray = 'arr{depth}'.format(depth = depth)

            out.indent += 1

            if depth == len(self.arrdef) - 1:
                out.writeline('{name}{subscript}.setIndex({array}[i{depth}]);'.format(name = self.refname, subscript = subscript, array = array, depth = depth))
            else:
                out.writeline('UInt_t (&{newarray}){arrdef}({array}[i{depth}]);'.format(newarray = newarray, arrdef = self.arrdef_text(depth + 1), depth = depth))

            array = newarray

        for depth in range(len(self.arrdef)):
            out.indent -= 1
            out.writeline('}')

    def write_assign(self, out, context):
        if self.is_array():
            index = ''
            for depth in range(len(self.arrdef)):
                out.writeline('for (UInt_t i{depth}(0); i{depth} != {n}; ++i{depth}) {{'.format(depth = depth, n = self.arrdef[depth]))
                out.indent += 1
                index += '[i{depth}]'.format(depth = depth)

            out.writeline('{name}{index} = _src.{name}{index};'.format(name = self.refname, index = index))

            for depth in range(len(self.arrdef)):
                out.indent -= 1
                out.writeline('}')

        else:
            out.writeline('{name} = _src.{name};'.format(name = self.refname))

    def write_init(self, out, context):
        if not self.is_array():
            out.writeline('{name}.init();'.format(name = self.refname))


class ObjBranchDef(Definition):
    """
    Composite object "branch" definition. Definition file syntax:
    <name>/<type>(|Collection|Array)
    where <type> can be an object name or ROOT leaf type symbol.
    """

    def __init__(self, line):
        Definition.__init__(self, line, '([a-zA-Z_][a-zA-Z0-9_]*)/([^ ]+)$')

        self.name = self.matches.group(1)
        self.objname = self.matches.group(2)
        if self.objname.endswith('Collection'):
            self.objname = self.objname.replace('Collection', '')
            self.conttype = 'Collection'
        elif self.objname.endswith('Array'):
            self.objname = self.objname.replace('Array', '')
            self.conttype = 'Array'
        else:
            self.conttype = ''

        try:
            # is this a valid object?
            objdef = PhysicsObjectDef.get(self.objname)
        except KeyError:
            raise Definition.NoMatch

        if objdef.coltype() == PhysicsObjectDef.SINGLE and self.conttype != '':
            raise RuntimeError('Cannot create container of object ' + objdef.name)
        elif objdef.coltype() == PhysicsObjectDef.DYNAMIC and self.conttype == 'Array':
            raise RuntimeError('Cannot create array of object ' + objdef.name)
        elif objdef.coltype() == PhysicsObjectDef.FIXED and self.conttype == 'Collection':
            raise RuntimeError('Cannot create collection of object ' + objdef.name)

    def type(self):
        return self.objname + self.conttype

    def write_decl(self, out):
        out.writeline('{objname}{type} {name} = {objname}{type}("{name}");'.format(objname = self.objname, type = self.conttype, name = self.name))

    def write_set_status(self, out):
        out.writeline('{name}.setStatus(_tree, _status, _branches.subList("{name}"));'.format(name = self.name))

    def write_set_address(self, out):
        out.writeline('{name}.setAddress(_tree, _branches.subList("{name}"), _setStatus);'.format(name = self.name))

    def write_book(self, out):
        out.writeline('{name}.book(_tree, _branches.subList("{name}"));'.format(name = self.name))

    def write_release_tree(self, out):
        if self.conttype == '':
            out.writeline('{name}.resetAddress(_tree);'.format(name = self.name))
        else:
            out.writeline('{name}.releaseTree(_tree);'.format(name = self.name))

    def cpyctor(self):
        return '{name}(_src.{name})'.format(name = self.name)

    def write_assign(self, out):
        out.writeline('{name} = _src.{name};'.format(name = self.name))

    def write_init(self, out):
        out.writeline('{name}.init();'.format(name = self.name))


class FunctionDef(Definition):
    """
    Function branch definition. Write as a C++ function within the given scope.
    """

    def __init__(self, line, source):
        Definition.__init__(self, line, '((?:virtual +|static +|)([^\(]+) +([^ \(]+\([^\)]*\)(?: +const|))(?: +override|)) *(.*)')

        self.decl = self.matches.group(1) # includes virtual/static, const, override
        self.type = self.matches.group(2) # return type
        self.signature = self.matches.group(3) # function name and arguments

        self.impl = ''

        if self.matches.group(4) == ';':
            # implementation must be given by hand in the .cc file
            return

        self.impl += self.matches.group(4)

        depth = self.impl.count('{') - self.impl.count('}')

        if '{' in self.impl and depth == 0:
            return

        while True:
            line = source.readline()
            if line == '':
                break

            self.impl += line

            depth += line.count('{')
            depth -= line.count('}')

            if depth == 0:
                break

    def write_decl(self, out, context):
        if context == 'global':
            out.writeline(self.decl + ';')

        elif context == 'class':
            if '\n' not in self.impl: # a one-liner -> write directly in decl
                out.writeline('{decl} {impl}'.format(decl = self.decl, impl = self.impl))
            else:
                out.writeline('{decl};'.format(decl = self.decl))

    def write_def(self, out, context):
        # comment out default arguments - won't work if the default value is a string that contains , or )
        signature = re.sub(' *= *[^,)]+', lambda m: '/*' + m.group(0) + '*/', self.signature)
        if context == 'global':
            out.writeline(self.type)
            out.writeline('{NAMESPACE}::{sign}'.format(NAMESPACE = NAMESPACE, sign = signature))
            for line in self.impl.split('\n'):
                out.writeline(line)

        else:
            if '\n' not in self.impl:
                return

            # context is the class name
            out.writeline(self.type)
            out.writeline('{NAMESPACE}::{cls}::{sign}'.format(NAMESPACE = NAMESPACE, cls = context, sign = signature))
            for line in self.impl.split('\n'):
                out.writeline(line)


class ObjectDef(object):
    """
    Base class for physics objects and tree entry objects.
    """

    def __init__(self, name, source):
        """
        Constructor called either by PhysicsObjectDef or TreeDef.
        Parse the source text block and collect all information on this object.
        """

        self.name = name
        self.includes = []
        self.constants = []
        self.objbranches = []
        self.branches = []
        self.references = []
        self.functions = []

        while True:
            line = source.readline()
            line = line.strip()

            if line == '':
                break

            try:
                self.includes.append(Include(line))
                continue
            except Definition.NoMatch:
                pass

            try:
                self.constants.append(Constant(line))
                continue
            except Definition.NoMatch:
                pass

            try:
                self.branches.append(RefBranchDef(line))
                continue
            except Definition.NoMatch:
                pass

            try:
                self.objbranches.append(ObjBranchDef(line))
                continue
            except Definition.NoMatch:
                pass

            try:
                self.branches.append(BranchDef(line))
                continue
            except Definition.NoMatch:
                pass

            try:
                self.references.append(ReferenceDef(line))
                continue
            except Definition.NoMatch:
                pass
            
            try:
                self.functions.append(FunctionDef(line, source))
                continue
            except Definition.NoMatch:
                pass

            break


class PhysicsObjectDef(Definition, ObjectDef):
    """
    Physics object definition. Definition file syntax:
    
    [<Name>(><Parent>):<max size | SINGLE>]
    <variable definitions>
    <function definitions>
    """

    DYNAMIC, FIXED, SINGLE = range(3)

    _known_objects = []

    @staticmethod
    def get(name):
        try:
            return next(o for o in PhysicsObjectDef._known_objects if o.name == name)
        except StopIteration:
            raise KeyError('PhysicsObjectDef.get({name})'.format(name = name))

    def __init__(self, line, source):
        """
        Argument: re match object
        """

        Definition.__init__(self, line, '\\[([A-Z][a-zA-Z0-9]+)(>[A-Z][a-zA-Z0-9]+|)(\\:SINGLE|\\:MAX=.+|\\:SIZE=.+|)\\] *$')
        PhysicsObjectDef._known_objects.append(self)

        self._sizestr = None

        # collection definition (optional)
        coldef = self.matches.group(3)
       
        if coldef == ':SINGLE':
            self.parent = 'Singlet'
            self._coltype = PhysicsObjectDef.SINGLE

        elif coldef.startswith(':MAX'):
            self.parent = 'ContainerElement'
            self._coltype = PhysicsObjectDef.DYNAMIC
            self._sizestr = coldef[5:]
            
        elif coldef.startswith(':SIZE'):
            self.parent = 'ContainerElement'
            self._coltype = PhysicsObjectDef.FIXED
            self._sizestr = coldef[6:]

        # if >parent is present, update the parent class name
        if self.matches.group(2):
            self.parent = self.matches.group(2)[1:]
            self._coltype = None
        elif not self.parent:
            raise RuntimeError('No parent or size specified for class {name}'.format(name = self.matches.group(1)))

        ObjectDef.__init__(self, self.matches.group(1), source)

    def coltype(self):
        if self._coltype is None:
            return PhysicsObjectDef.get(self.parent).coltype()
        else:
            return self._coltype

    def container(self):
        if self.coltype() == PhysicsObjectDef.DYNAMIC:
            return 'Collection'
        elif self.coltype() == PhysicsObjectDef.FIXED:
            return 'Array'
        else:
            return ''

    def sizestr(self):
        if self._sizestr is None:
            return PhysicsObjectDef.get(self.parent).sizestr()
        else:
            return self._sizestr

    def generate_header(self):
        """
        Write a header file.
        """

        inheritance = [self]
        while True:
            try:
                inheritance.insert(0, PhysicsObjectDef.get(inheritance[0].parent))
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

        for include in self.includes:
            if include.code not in included:
                include.write(header)
                included.append(include.code)

        refobjects = []
        for branch in self.branches:
            if type(branch) is RefBranchDef:
                refobjects.append(branch.objname)
                stmt = '#include "{obj}.h"'.format(obj = branch.objname)
                if stmt not in included:
                    header.writeline(stmt)
                    included.append(stmt)

        header.newline()
        header.writeline('namespace {NAMESPACE} {{'.format(NAMESPACE = NAMESPACE))
        header.newline()
        header.indent += 1

        if len(refobjects):
            for obj in refobjects:
                header.writeline('class {obj};'.format(obj = obj))
            header.newline()

        header.writeline('class {name} : public {parent} {{'.format(name = self.name, parent = self.parent))
        header.writeline('public:')
        header.indent += 1
        
        if self.coltype() != PhysicsObjectDef.SINGLE:
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
            header.writeline('void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;')
            header.writeline('void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;')
            header.writeline('void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;')
            header.writeline('void resetAddress(TTree&, TString const&) override;')
            header.indent -= 1
            header.writeline('};')
            header.newline()

            header.writeline('typedef {parent} base_type;'.format(parent = self.parent))
            header.writeline('typedef Container<{name}, {parent}::array_type> array_type;'.format(name = self.name, parent = self.parent))
            header.writeline('typedef Container<{name}, {parent}::collection_type> collection_type;'.format(name = self.name, parent = self.parent))
            header.newline()

        # "boilerplate" functions (default ctor for non-SINGLE objects are pretty nontrivial though)
        header.writeline('{name}(char const* name = "");'.format(name = self.name)) # default constructor
        header.writeline('{name}({name} const&);'.format(name = self.name)) # copy constructor

        # standard constructors and specific functions
        if self.coltype() != PhysicsObjectDef.SINGLE:
            # whereas elements of collections are constructed from an array and an index
            header.writeline('{name}(datastore&, UInt_t idx);'.format(name = self.name))

        header.writeline('~{name}();'.format(name = self.name)) # destructor
        header.writeline('{name}& operator=({name} const&);'.format(name = self.name)) # assignment operator

        header.newline()

        # I/O with default name
        header.writeline('void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;')
        header.writeline('void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;')
        header.writeline('void book(TTree&, utils::BranchList const& = {"*"}) override;')
        header.writeline('void resetAddress(TTree&) override;')

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

        if self.coltype() == PhysicsObjectDef.SINGLE:
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
        if len(header.custom_blocks) != 0:
            header.write(header.custom_blocks[0])
        else:
            header.writeline('/* BEGIN CUSTOM */')
            header.writeline('/* END CUSTOM */')

        if self.coltype() != PhysicsObjectDef.SINGLE:
            header.newline()
            header.indent -= 1
            header.writeline('protected:')
            header.indent += 1
            header.writeline('{name}(ArrayBase*);'.format(name = self.name))

        header.indent -= 1

        header.writeline('};')

        header.newline()

        if self.coltype() != PhysicsObjectDef.SINGLE:
            header.writeline('typedef {name}::array_type {name}Array;'.format(name = self.name))
            header.writeline('typedef {name}::collection_type {name}Collection;'.format(name = self.name))
            header.writeline('typedef Ref<{name}> {name}Ref;'.format(name = self.name))
            header.newline()

        if len(header.custom_blocks) > 1:
            header.write(header.custom_blocks[1])
        else:
            header.writeline('/* BEGIN CUSTOM */')
            header.writeline('/* END CUSTOM */')
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

        if self.coltype() == PhysicsObjectDef.SINGLE:
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
            for branch in self.branches:
                if branch.is_array():
                    branch.write_assign(src, context = 'Singlet')
            src.indent -= 1
            src.writeline('}')
            src.newline()

            src.writeline('{NAMESPACE}::{name}::~{name}()'.format(**subst))
            src.writeline('{')
            src.writeline('}')

            methods = [
                ('operator=', '{NAMESPACE}::{name}&'.format(**subst), [('{name} const&'.format(**subst), '_src')], 'write_assign', '*this'),
                ('setStatus', 'void', [('TTree&', '_tree'), ('Bool_t', '_status'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_set_status', None),
                ('setAddress', 'void', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}'), ('Bool_t', '_setStatus', 'kTRUE')], 'write_set_address', None),
                ('book', 'void', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_book', None),
                ('resetAddress', 'void', [('TTree&', '_tree')], 'write_reset_address', None),
                ('init', 'void', [], 'write_init', None)
            ]

            for method in methods:
                src.newline()
                self._write_method(src, 'Singlet', method)

        #if self.coltype == PhysicsObjectDef.SINGLE:
        else:
            size_lines = ['TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));']
            methods = [
                ('allocate', 'void', [('UInt_t', '_nmax')], 'write_allocate', None),
                ('deallocate', 'void', [], 'write_deallocate', None),
                ('setStatus', 'void', [('TTree&', '_tree'), ('TString const&', '_name'), ('Bool_t', '_status'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_set_status', None),
                ('setAddress', 'void', [('TTree&', '_tree'), ('TString const&', '_name'), ('utils::BranchList const&', '_branches', '{"*"}'), ('Bool_t', '_setStatus', 'kTRUE')], 'write_set_address', None),
                ('book', 'void', [('TTree&', '_tree'), ('TString const&', '_name'), ('utils::BranchList const&', '_branches', '{"*"}'), ('Bool_t', '_dynamic', 'kTRUE')], 'write_book', None, size_lines),
                ('resetAddress', 'void', [('TTree&', '_tree'), ('TString const&', '_name')], 'write_reset_address', None)
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
                src.newline()
                for branch in self.branches:
                    branch.write_assign(src, context = 'ContainerElement')
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
            src.writeline('gStore.free(this);')
            src.indent -= 1
            src.writeline('}')

            name_line = 'TString name(gStore.getName(this));'
            methods = [
                ('operator=', '{NAMESPACE}::{name}&'.format(**subst), [('{name} const&'.format(**subst), '_src')], 'write_assign', '*this'),
                ('setStatus', 'void', [('TTree&', '_tree'), ('Bool_t', '_status'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_set_status', None, [name_line]),
                ('setAddress', 'void', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}'), ('Bool_t', '_setStatus', 'kTRUE')], 'write_set_address', None, [name_line]),
                ('book', 'void', [('TTree&', '_tree'), ('utils::BranchList const&', '_branches', '{"*"}')], 'write_book', None, [name_line]),
                ('resetAddress', 'void', [('TTree&', '_tree')], 'write_reset_address', None, [name_line]),
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
        if len(src.custom_blocks) != 0:
            src.write(src.custom_blocks[0])
        else:
            src.writeline('/* BEGIN CUSTOM */')
            src.writeline('/* END CUSTOM */')

        src.close()


class TreeDef(Definition, ObjectDef):
    """
    Tree definition. Definition file syntax:

    {<Name>}
    <branch definitions>
    <function definitions>
    """

    def __init__(self, re_matches, source):
        Definition.__init__(self, line, '\\{([^\\}]+)\\}$')
        ObjectDef.__init__(self, self.matches.group(1), source)

    def generate_header(self):
        """
        Write the header file.
        """

        header = FileOutput('{PACKDIR}/Objects/interface/{name}.h'.format(PACKDIR = PACKDIR, name = self.name))
        header.writeline('#ifndef {PACKAGE}_Objects_{name}_h'.format(PACKAGE = PACKAGE, name = self.name))
        header.writeline('#define {PACKAGE}_Objects_{name}_h'.format(PACKAGE = PACKAGE, name = self.name))
        header.writeline('#include "Constants.h"')

        included = []
        for objbranch in self.objbranches:
            if objbranch.objname not in included:
                header.writeline('#include "{brobj}.h"'.format(brobj = objbranch.objname))
                included.append(objbranch.objname)

        header.writeline('#include "../../Framework/interface/TreeEntry.h"')

        for include in self.includes:
            include.write(header)

        header.newline()
        header.writeline('namespace {NAMESPACE} {{'.format(NAMESPACE = NAMESPACE))
        header.newline()
        header.indent += 1

        header.writeline('class {name} : public TreeEntry {{'.format(name = self.name))
        header.writeline('public:')
        header.indent += 1
        
        header.writeline('{name}();'.format(name = self.name)) # default constructor
        header.writeline('{name}({name} const&);'.format(name = self.name)) # copy constructor
        header.writeline('~{name}() {{}}'.format(name = self.name)) # destructor
        header.writeline('{name}& operator=({name} const&);'.format(name = self.name)) # assignment operator

        header.newline()
        header.writeline('void init() override;')

        if len(self.functions) != 0:
            header.newline()
            for function in self.functions:
                function.write_decl(header, context = 'class')

        if len(self.objbranches) != 0:
            header.newline()
            for objbranch in self.objbranches:
                objbranch.write_decl(header)

        if len(self.branches) != 0:
            header.newline()
            for branch in self.branches:
                branch.write_decl(header, context = 'TreeEntry')

        header.newline()
        header.indent -= 1
        header.writeline('protected:')
        header.indent += 1
        header.writeline('void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) override;')
        header.writeline('void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;')
        header.writeline('void doBook_(TTree&, utils::BranchList const&) override;')
        header.writeline('void doReleaseTree_(TTree&) override;')

        header.newline()
        header.indent -= 1
        header.writeline('public:')
        header.indent += 1
        if len(header.custom_blocks) != 0:
            header.write(header.custom_blocks[0])
        else:
            header.writeline('/* BEGIN CUSTOM */')
            header.writeline('/* END CUSTOM */')

        header.indent -= 1

        header.writeline('};')

        header.newline()
        if len(header.custom_blocks) > 1:
            header.write(header.custom_blocks[1])
        else:
            header.writeline('/* BEGIN CUSTOM */')
            header.writeline('/* END CUSTOM */')

        header.newline()

        header.indent -= 1
        header.writeline('}')
        header.newline()

        header.writeline('#endif')
        header.close()

    def generate_source(self):
        """
        Write the .cc file.
        """

        src = FileOutput('{PACKDIR}/Objects/src/{name}.cc'.format(PACKDIR = PACKDIR, name = self.name))
        src.writeline('#include "../interface/{name}.h"'.format(name = self.name))
        src.newline()

        src.writeline('{NAMESPACE}::{name}::{name}() :'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.indent += 1
        src.writeline('TreeEntry()')
        src.indent -= 1
        src.writeline('{')
        src.indent += 1
        for ref in self.references:
            ref.write_def(src)
        src.indent -= 1
        src.writeline('}')
        src.newline()

        src.writeline('{NAMESPACE}::{name}::{name}({name} const& _src) :'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.indent += 1
        initializers = ['TreeEntry()']
        for objbranch in self.objbranches:
            initializers.append(objbranch.cpyctor())
        for branch in self.branches:
            branch.init_copy(initializers, context = 'TreeEntry')
        src.writelines(initializers, ',')
        src.indent -= 1
        src.writeline('{')
        src.indent += 1
        for branch in self.branches:
            if branch.is_array():
                branch.write_assign(src, context = 'TreeEntry')
        for ref in self.references:
            ref.write_def(src)
        src.indent -= 1
        src.writeline('}')
        src.newline()

        src.writeline('{NAMESPACE}::{name}&'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.writeline('{NAMESPACE}::{name}::operator=({name} const& _src)'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.writeline('{')
        src.indent += 1
        if len(self.branches) != 0:
            for branch in self.branches:
                branch.write_assign(src, context = 'TreeEntry')
            src.newline()
        if len(self.references) != 0:
            for ref in self.references:
                ref.write_def(src)
            src.newline()
        src.writeline('return *this;')
        src.indent -= 1
        src.writeline('}')
        src.newline()

        src.writeline('void')
        src.writeline('{NAMESPACE}::{name}::init()'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.writeline('{')
        src.indent += 1
        for objbranch in self.objbranches:
            objbranch.write_init(src)
        for branch in self.branches:
            branch.write_init(src, context = 'TreeEntry')
        src.indent -= 1
        src.writeline('}')
        src.newline()

        src.writeline('/*protected*/')
        src.writeline('void')
        src.writeline('{NAMESPACE}::{name}::doSetStatus_(TTree& _tree, Bool_t _status, utils::BranchList const& _branches)'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.writeline('{')
        src.indent += 1
        for objbranch in self.objbranches:
            objbranch.write_set_status(src)
        for branch in self.branches:
            branch.write_set_status(src, context = 'TreeEntry')
        src.indent -= 1
        src.writeline('}')
        src.newline()

        src.writeline('/*protected*/')
        src.writeline('void')
        src.writeline('{NAMESPACE}::{name}::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.writeline('{')
        src.indent += 1
        for objbranch in self.objbranches:
            objbranch.write_set_address(src)
        for branch in self.branches:
            branch.write_set_address(src, context = 'TreeEntry')
        src.indent -= 1
        src.writeline('}')
        src.newline()

        src.writeline('/*protected*/')
        src.writeline('void')
        src.writeline('{NAMESPACE}::{name}::doBook_(TTree& _tree, utils::BranchList const& _branches)'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.writeline('{')
        src.indent += 1
        for objbranch in self.objbranches:
            objbranch.write_book(src)
        for branch in self.branches:
            branch.write_book(src, context = 'TreeEntry')
        src.indent -= 1
        src.writeline('}')
        src.newline()

        src.writeline('/*protected*/')
        src.writeline('void')
        src.writeline('{NAMESPACE}::{name}::doReleaseTree_(TTree& _tree)'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.writeline('{')
        src.indent += 1
        for objbranch in self.objbranches:
            objbranch.write_release_tree(src)
        src.indent -= 1
        src.writeline('}')
        src.newline()

        if len(self.functions) != 0:
            src.newline()
            for function in self.functions:
                function.write_def(src, context = self.name)

        src.newline()
        if len(src.custom_blocks) != 0:
            src.write(src.custom_blocks[0])
        else:
            src.writeline('/* BEGIN CUSTOM */')
            src.writeline('/* END CUSTOM */')

        src.close()


class ReferenceDef(Definition):
    """
    Sets reference within a tree definition. Syntax:
    <branch>(.<branch>)-><collection>
    """

    def __init__(self, line):
        Definition.__init__(self, line, '([^ ]+)->([^ ]+)')
        self.ref_name = self.matches.group(1)
        self.target = self.matches.group(2)

    def write_def(self, out):
        """
        Part of the tree entry constructor code to pass the target collection pointer to the reference.
        """

        rnames = self.ref_name.split('.')
        if len(rnames) == 1:
            out.writeline('{rname}.setContainer({target});'.format(rname = rnames[0], target = self.target))
        elif len(rnames) == 2:
            out.writeline('for (auto& p : {robj})'.format(robj = rnames[0]))
            out.writeline('  p.{rname}.setContainer({target});'.format(rname = rnames[1], target = self.target))
        

class FileOutput(object):
    """
    Helper tool to write C++ code output.
    """

    def __init__(self, fname):
        self.custom_blocks = []
        if PRESERVE_CUSTOM:
            try:
                original = open(fname)
                while True:
                    line = original.readline()
                    if not line:
                        break
                    
                    if '/* BEGIN CUSTOM */' not in line:
                        continue
    
                    block = line
                    while True:
                        line = original.readline()
                        block += line
                        if not line or '/* END CUSTOM */' in line:
                            break
    
                    self.custom_blocks.append(block)
                
                original.close()
            except IOError:
                pass

        self._file = open(fname, 'w')
        self.indent = 0

    def close(self):
        self._file.close()

    def write(self, text):
        self._file.write(text)

    def newline(self):
        self._file.write('\n')

    def writeline(self, line):
        self._file.write(('  ' * self.indent) + line + '\n')

    def writelines(self, lines, line_end = ''):
        indented_lines = []
        for line in lines:
            indented_lines.append(('  ' * self.indent) + line)

        self._file.write((line_end + '\n').join(indented_lines) + '\n')


if __name__ == '__main__':
    from argparse import ArgumentParser

    argParser = ArgumentParser(description = 'Generate C++ code for a flat tree')
    argParser.add_argument('configs', metavar = 'CONFIG', nargs = '+', help = 'Tree definition files.')
    argParser.add_argument('--clear-custom', '-C', dest = 'clear_custom', action = 'store_true', help = 'Clear custom code.')
    
    args = argParser.parse_args()

    if args.clear_custom:
        PRESERVE_CUSTOM = False

    # globals
    includes = [
        Include('#include "TTree.h"'),
        Include('#include "TString.h"'),
        Include('#include "Rtypes.h"')
    ]
    typedefs = []
    constants = []
    asserts = []
    enums = []
    functions = []
    phobjects = []
    trees = []

    # parse all config files
    for fname in args.configs:
        configFile = open(fname)
    
        while True:
            line = configFile.readline()
            if line == '':
                break
    
            line = line.strip()
            
            if line == '':
                continue
    
            if line.startswith('%'):
                #comment line
                continue
    
            try:
                includes.append(Include(line))
                continue
            except Definition.NoMatch:
                pass
    
            try:
                typedefs.append(Typedef(line))
                continue
            except Definition.NoMatch:
                pass
    
            try:
                constants.append(Constant(line))
                continue
            except Definition.NoMatch:
                pass
    
            try:
                asserts.append(AssertDef(line))
                continue
            except Definition.NoMatch:
                pass
    
            try:
                enums.append(EnumDef(line, configFile))
                continue
            except Definition.NoMatch:
                pass
    
            try:
                functions.append(FunctionDef(line, configFile))
                continue
            except Definition.NoMatch:
                pass
    
            try:
                phobjects.append(PhysicsObjectDef(line, configFile))
                continue
            except Definition.NoMatch:
                pass
    
            try:
                trees.append(TreeDef(line, configFile))
                continue
            except Definition.NoMatch:
                pass
    
            print 'Skipping unrecognized pattern:', line
    
        configFile.close()
   
    # create directories if necessary
    if not os.path.isdir(PACKDIR + '/Objects/interface'):
        os.makedirs(PACKDIR + '/Objects/interface')
    if not os.path.isdir(PACKDIR + '/Objects/src'):
        os.makedirs(PACKDIR + '/Objects/src')
    if not os.path.isdir(PACKDIR + '/obj'):
        os.makedirs(PACKDIR + '/obj')

    # are we running in a CMSSW environment?
    if os.path.exists(PACKDIR + '/../../.SCRAM/Environment'):
        with open(PACKDIR + '/../../.SCRAM/Environment') as environment:
            if 'CMSSW' in environment.readline():
                # if so, we need to write the build file
                with open(PACKDIR + '/Objects/BuildFile.xml', 'w') as buildFile:
                    buildFile.write('<use name="root"/>\n')
                    buildFile.write('<use name="{PACKAGE}/Framework"/>\n'.format(PACKAGE = PACKAGE))
                    buildFile.write('<export>\n')
                    buildFile.write('  <lib name="1"/>\n')
                    buildFile.write('</export>\n')

    # write the globals file
    header = FileOutput(PACKDIR + '/Objects/interface/Constants.h')
    header.writeline('#ifndef {PACKAGE}_Objects_Constants_h'.format(PACKAGE = PACKAGE))
    header.writeline('#define {PACKAGE}_Objects_Constants_h'.format(PACKAGE = PACKAGE))
    header.newline()

    for include in includes:
        include.write(header)

    header.writeline('#include <cstring>')

    header.newline()
    header.writeline('namespace {NAMESPACE} {{'.format(NAMESPACE = NAMESPACE))
    header.newline()
    header.indent += 1

    if len(typedefs) != 0:
        for typedef in typedefs:
            typedef.write(header)

        header.newline()

    for enum in enums:
        enum.write_decl(header)
        header.newline()

    if len(constants) != 0:
        for constant in constants:
            constant.write_decl(header, context = 'global')

        header.newline()

    AssertDef.write(asserts, header)

    for function in functions:
        function.write_decl(header, context = 'global')
        header.newline()

    if len(header.custom_blocks) != 0:
        header.write(header.custom_blocks[0])
    else:
        header.writeline('/* BEGIN CUSTOM */')
        header.writeline('/* END CUSTOM */')
    header.newline()

    header.indent -= 1
    header.writeline('}')

    header.newline()

    header.writeline('#endif')
    header.close()

    # .cc for constants
    src = FileOutput(PACKDIR + '/Objects/src/Constants.cc')
    src.writeline('#include "../interface/Constants.h"')

    for enum in enums:
        src.newline()
        enum.write_def(src)

    for function in functions:
        src.newline()
        function.write_def(src, context = 'global')

    src.newline()
    if len(src.custom_blocks) != 0:
        src.write(src.custom_blocks[0])
    else:
        src.writeline('/* BEGIN CUSTOM */')
        src.writeline('/* END CUSTOM */')

    src.close()

    # write code for all objects and trees
    for objdef in phobjects + trees:
        objdef.generate_header()
        objdef.generate_source()

    # write a linkdef file (not compiled by CMSSW - only for Makefile)
    linkdef = FileOutput(PACKDIR + '/obj/LinkDef.h')
    linkdef.writeline('#include "../Framework/interface/Object.h"')
    linkdef.writeline('#include "../Framework/interface/Container.h"')
    for objdef in phobjects:
        linkdef.writeline('#include "../Objects/interface/{name}.h"'.format(name = objdef.name))
    for tree in trees:
        linkdef.writeline('#include "../Objects/interface/{name}.h"'.format(name = tree.name))

    linkdef.newline()

    linkdef.writeline('#ifdef __CLING__')
    linkdef.writeline('#pragma link off all globals;')
    linkdef.writeline('#pragma link off all classes;')
    linkdef.writeline('#pragma link off all functions;')

    linkdef.writeline('#pragma link C++ nestedclass;')
    linkdef.writeline('#pragma link C++ nestedtypedef;')
    linkdef.writeline('#pragma link C++ namespace {NAMESPACE};'.format(NAMESPACE = NAMESPACE))

    linkdef.newline()

    for enum in enums:
        linkdef.writeline('#pragma link C++ enum {NAMESPACE}::{name};'.format(NAMESPACE = NAMESPACE, name = enum.name))

    for objdef in phobjects:
        linkdef.writeline('#pragma link C++ class {NAMESPACE}::{name};'.format(NAMESPACE = NAMESPACE, name = objdef.name))

    for objdef in phobjects:
        if objdef.coltype() == PhysicsObjectDef.DYNAMIC:
            conttype = 'Collection'
        elif objdef.coltype() == PhysicsObjectDef.FIXED:
            conttype = 'Array'
        else:
            continue

        if objdef.parent == 'ContainerElement':
            parent = conttype
        else:
            parent = objdef.parent + conttype

        linkdef.writeline('#pragma link C++ class Container<{NAMESPACE}::{name}, {NAMESPACE}::{parent}>;'.format(NAMESPACE = NAMESPACE, name = objdef.name, parent = parent))
        linkdef.writeline('#pragma link C++ typedef {NAMESPACE}::{name}{type};'.format(NAMESPACE = NAMESPACE, name = objdef.name, type = conttype))

    for tree in trees:
        linkdef.writeline('#pragma link C++ class {NAMESPACE}::{name};'.format(NAMESPACE = NAMESPACE, name = tree.name))

    linkdef.newline()

    linkdef.writeline('#endif')
