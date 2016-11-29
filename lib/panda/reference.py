from base import Definition

class Reference(Definition):
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
