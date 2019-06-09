from common import *
from base import Definition
from obj import Object
from output import FileOutput

class Mixin(Definition, Object):
    """
    Physics object definition. Definition file syntax:
    
    <Name>
    <variable definitions>
    <function definitions>
    """

    def __init__(self, line, source):
        """
        Argument: re match object
        """

        Definition.__init__(self, line, '<([A-Z][a-zA-Z0-9]+)>$')
        Object.__init__(self, self.matches.group(1), source)

    def generate_header(self):
        header = FileOutput('{PACKDIR}/Objects/interface/{name}.h'.format(PACKDIR = PACKDIR, name = self.name))
        header.writeline('#ifndef {PACKAGE}_Objects_{name}_h'.format(PACKAGE = PACKAGE, name = self.name))
        header.writeline('#define {PACKAGE}_Objects_{name}_h'.format(PACKAGE = PACKAGE, name = self.name))

        header.writeline('#include "../../Framework/interface/Element.h"')

        header.newline()
        header.writeline('namespace {NAMESPACE} {{'.format(NAMESPACE = NAMESPACE))
        header.newline()
        header.indent += 1

        header.writeline('class {name} {{'.format(name = self.name))
        header.writeline('public:')
        header.indent += 1

        if len(self.enums) != 0:
            for enum in self.enums:
                enum.write_decl(header, context = 'class')
            header.newline()

        if len(self.constants) != 0:
            for constant in self.constants:
                constant.write_decl(header, context = 'class')
            header.newline()

        header.writeline('struct datastore {')
        header.indent += 1

        for branch in self.branches:
            branch.write_decl(header, context = 'datastore')

        header.indent -= 1
        header.writeline('};')
        header.newline()

        header.writeline('{name}(datastore&, UInt_t idx);'.format(name = self.name))
        #header.writeline('~{name}();'.format(name = self.name)) # destructor

        header.newline()

        has_public = False
        for branch in self.branches:
            if not hasattr(branch, 'refname') and branch.name.endswith('_'):
                continue

            has_public = True
            branch.write_decl(header, context = 'Element')

        if has_public:
            header.newline()

        has_protected = False
        for branch in self.branches:
            if hasattr(branch, 'refname') or not branch.name.endswith('_'):
                continue

            if not has_protected:
                header.indent -= 1
                header.writeline('protected:')
                header.indent += 1
                has_protected = True
                
            branch.write_decl(header, context = 'Element')

        if has_protected:
            header.newline()
            
        header.write_custom_block('{name}.h.classdef'.format(name = self.name))

        header.indent -= 1
        
        header.writeline('};')

        header.write_custom_block('{name}.h.global'.format(name = self.name))
        header.newline()

        header.indent -= 1
        header.writeline('}')
        header.newline()

        header.writeline('#endif')
        header.close()

    def generate_source(self):
        subst = {'NAMESPACE': NAMESPACE, 'name': self.name}
        
        src = FileOutput('{PACKDIR}/Objects/src/{name}.cc'.format(PACKDIR = PACKDIR, **subst))
        src.writeline('#include "../interface/{name}.h"'.format(**subst))

        if len(self.enums) != 0:
            src.newline()
            for enum in self.enums:
                enum.write_def(src, cls = '{NAMESPACE}::{name}'.format(**subst))

        if len(self.constants) != 0:
            src.newline()
            for constant in self.constants:
                constant.write_def(src, cls = '{NAMESPACE}::{name}'.format(**subst))

        src.newline()
        src.writeline('{NAMESPACE}::{name}::{name}(datastore& _data, UInt_t _idx) :'.format(**subst))
        src.indent += 1
        initializers = []
        for branch in self.branches:
            branch.init_standard(initializers, context = 'Element')
        src.writelines(initializers, ',')
        src.indent -= 1
        src.writeline('{')
        src.indent += 1
        for branch in self.branches:
            branch.write_standard_ctor(src, context = 'Element')
        src.indent -= 1
        src.writeline('}')

        src.newline()
        src.write_custom_block('{name}.cc.global'.format(**subst))

