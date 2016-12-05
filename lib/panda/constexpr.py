from common import NAMESPACE
from base import Definition

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


class Assert(Definition):
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

        enum = Enum('enum Assertions {', asserts)
        enum.write_decl(out, names = False)

    def __init__(self, line):
        Definition.__init__(self, line, 'ASSERT +(.+)')


class Enum(Definition):
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
        out.writeline('TString* name(new TString);')
        out.writeline('tree->Branch("name", "TString", &name);')
        out.writeline('for (auto&& n : {name}Name) {{'.format(name = self.name))
        out.indent += 1
        out.writeline('*name = n;')
        out.writeline('tree->Fill();')
        out.indent -= 1
        out.writeline('}')
        out.writeline('tree->ResetBranchAddresses();')
        out.writeline('delete name;')
        out.writeline('return tree;')
        out.indent -= 1
        out.writeline('}')

