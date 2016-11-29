from common import *
from base import Definition
from obj import Object
from output import FileOutput

class Tree(Definition, Object):
    """
    Tree definition. Definition file syntax:

    {<Name>}
    <branch definitions>
    <function definitions>
    """

    def __init__(self, line, source):
        Definition.__init__(self, line, '\\{([^\\}]+)\\}$')
        Object.__init__(self, self.matches.group(1), source)

    def generate_header(self):
        """
        Write the header file.
        """

        header = FileOutput('{PACKDIR}/Objects/interface/{name}.h'.format(PACKDIR = PACKDIR, name = self.name))
        header.writeline('#ifndef {PACKAGE}_Objects_{name}_h'.format(PACKAGE = PACKAGE, name = self.name))
        header.writeline('#define {PACKAGE}_Objects_{name}_h'.format(PACKAGE = PACKAGE, name = self.name))
        header.writeline('#include "../../Framework/interface/TreeEntry.h"')
        header.writeline('#include "Constants.h"')

        included = []
        for objbranch in self.objbranches:
            if objbranch.objname not in included:
                header.writeline('#include "{brobj}.h"'.format(brobj = objbranch.objname))
                included.append(objbranch.objname)

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
        header.writeline('void adjustCollectionSizes_() override;')

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

        src.newline()
        src.writeline('sizeBranches_.clear();')
        for objbranch in self.objbranches:
            if objbranch.conttype == 'Collection':
                src.writeline('if (_tree.GetBranchStatus("{name}.size"))'.format(name = objbranch.name))
                src.indent += 1
                src.writeline('sizeBranches_.push_back(_tree.GetBranch("{name}.size"));'.format(name = objbranch.name))
                src.indent -= 1

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

        src.writeline('/*protected*/')
        src.writeline('void')
        src.writeline('{NAMESPACE}::{name}::adjustCollectionSizes_()'.format(NAMESPACE = NAMESPACE, name = self.name))
        src.writeline('{')
        src.indent += 1
        for objbranch in self.objbranches:
            if objbranch.conttype == 'Collection':
                src.writeline('{name}.resize({name}.size());'.format(name = objbranch.name))
        src.indent -= 1
        src.writeline('}')
        src.newline()

        src.close()
