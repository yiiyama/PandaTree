import re

from common import NAMESPACE
from base import Definition

class Function(Definition):
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
