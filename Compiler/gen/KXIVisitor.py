# Generated from C:/Compiler\KXI.g4 by ANTLR 4.9.2
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .KXIParser import KXIParser
else:
    from KXIParser import KXIParser

# This class defines a complete generic visitor for a parse tree produced by KXIParser.

class KXIVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by KXIParser#parameter.
    def visitParameter(self, ctx:KXIParser.ParameterContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by KXIParser#start.
    def visitStart(self, ctx:KXIParser.StartContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by KXIParser#r_type.
    def visitR_type(self, ctx:KXIParser.R_typeContext):
        return self.visitChildren(ctx)



del KXIParser