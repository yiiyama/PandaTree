from base import Definition
from branch import Branch
from physics import PhysicsObject

class RefBranch(Branch):
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
            objdef = PhysicsObject.get(self.objname)
        except KeyError:
            raise Definition.NoMatch

        if objdef.coltype() == PhysicsObject.SINGLE:
            raise RuntimeError('Cannot create reference to single object ' + objdef.name)

        # create a branch for the index with name {name}_
        Branch.__init__(self, '{name}_{arrdef}/i = -1'.format(name = self.refname, arrdef = arrdef, type = self.objname))

    def write_decl(self, out, context):
        if context == 'datastore':
            Branch.write_decl(self, out, context)
        else:
            if context == 'Singlet':
                out.indent -= 1
                out.writeline('protected:')
                out.indent += 1
                Branch.write_decl(self, out, context)
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
            Branch.write_set_address(self, out, context)

    def write_book(self, out, context):
        if context == 'ContainerElement':
            subscript = ''.join('[0]' for a in self.arrdef)
            out.writeline('utils::book(_tree, name, "{name}", "{arrdef}", \'{type}\', &{refname}{subscript}.idx(), _branches);'.format(name = self.name, arrdef = self.arrdef_text(), type = self.type, refname = self.refname, subscript = subscript))
        else:
            Branch.write_book(self, out, context)

    def write_reset_address(self, out, context):
        if context == 'ContainerElement':
            out.writeline('utils::resetAddress(_tree, name, "{name}");'.format(name = self.name))
        else:
            Branch.write_reset_address(self, out, context)

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
            Branch.init_copy(lines, context)
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
