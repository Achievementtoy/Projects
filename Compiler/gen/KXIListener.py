# Generated from C:/Compiler\KXI.g4 by ANTLR 4.9.2
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .KXIParser import KXIParser
else:
    from KXIParser import KXIParser

# This class defines a complete listener for a parse tree produced by KXIParser.
class KXIListener(ParseTreeListener):

    # Enter a parse tree produced by KXIParser#parameter.
    def enterParameter(self, ctx:KXIParser.ParameterContext):
        pass

    # Exit a parse tree produced by KXIParser#parameter.
    def exitParameter(self, ctx:KXIParser.ParameterContext):
        pass


    # Enter a parse tree produced by KXIParser#start.
    def enterStart(self, ctx:KXIParser.StartContext):
        pass

    # Exit a parse tree produced by KXIParser#start.
    def exitStart(self, ctx:KXIParser.StartContext):
        pass


    # Enter a parse tree produced by KXIParser#r_type.
    def enterR_type(self, ctx:KXIParser.R_typeContext):
        pass

    # Exit a parse tree produced by KXIParser#r_type.
    def exitR_type(self, ctx:KXIParser.R_typeContext):
        pass



del KXIParser