import re

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
