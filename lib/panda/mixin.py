from base import Definition
from obj import Object

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
