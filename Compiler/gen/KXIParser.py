# Generated from C:/Compiler\KXI.g4 by ANTLR 4.9.2
# encoding: utf-8
from antlr4 import *
from io import StringIO
import sys
if sys.version_info[1] > 5:
	from typing import TextIO
else:
	from typing.io import TextIO


def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3N")
        buf.write("\21\4\2\t\2\4\3\t\3\4\4\t\4\3\2\3\2\5\2\13\n\2\3\3\3\3")
        buf.write("\3\4\3\4\3\4\2\2\5\2\4\6\2\4\3\2\30\31\7\2\4\4\t\t\20")
        buf.write("\20\'\'JJ\2\16\2\n\3\2\2\2\4\f\3\2\2\2\6\16\3\2\2\2\b")
        buf.write("\13\5\6\4\2\t\13\7J\2\2\n\b\3\2\2\2\n\t\3\2\2\2\13\3\3")
        buf.write("\2\2\2\f\r\t\2\2\2\r\5\3\2\2\2\16\17\t\3\2\2\17\7\3\2")
        buf.write("\2\2\3\n")
        return buf.getvalue()


class KXIParser ( Parser ):

    grammarFileName = "KXI.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'atoi'", "'bool'", "'block'", "'break'", 
                     "'case'", "'class'", "'char'", "'cin'", "'cout'", "'default'", 
                     "'else'", "'false'", "'if'", "'int'", "'itoa'", "'kxi2022'", 
                     "'lock'", "'main'", "'new'", "'null'", "'object'", 
                     "'public'", "'private'", "'protected'", "'return'", 
                     "'release'", "'string'", "'spawn'", "'sym'", "'set'", 
                     "'switch'", "'this'", "'true'", "'thread'", "'unprotected'", 
                     "'unlock'", "'void'", "'while'", "'wait'", "<INVALID>", 
                     "':'", "';'", "'{'", "'}'", "'('", "')'", "'['", "']'", 
                     "'='", "'=='", "'!='", "'>='", "'<='", "'>'", "'<'", 
                     "'&&'", "'||'", "'+'", "'-'", "'*'", "'/'", "'+='", 
                     "'-='", "'*='", "'/='", "'>>'", "'<<'", "'.'", "','" ]

    symbolicNames = [ "<INVALID>", "ATOI", "BOOL", "BLOCK", "BREAK", "CASE", 
                      "CLASS", "CHAR", "CIN", "COUT", "DEFAULT", "ELSE", 
                      "FALSE", "IF", "INT", "ITOA", "KXI2022", "LOCK", "MAIN", 
                      "NEW", "NULL", "OBJECT", "PUBLIC", "PRIVATE", "PROTECTED", 
                      "RETURN", "RELEASE", "STRING", "SPAWN", "SYM", "SET", 
                      "SWITCH", "THIS", "TRUE", "THREAD", "UNPROTECTED", 
                      "UNLOCK", "VOID", "WHILE", "WAIT", "WHITESPACE", "COLON", 
                      "SEMI", "LEFTBRACE", "RIGHTBRACE", "LEFTPARAN", "RIGHTPARAN", 
                      "LEFTBRACKET", "RIGHTBRACKET", "EQUALS", "ISEQUALTO", 
                      "NOTEQUAL", "GREATEREQUAL", "LESSEQUAL", "GREATERTHAN", 
                      "LESSTHAN", "AND", "OR", "ADD", "SUB", "MUL", "DIV", 
                      "PLUSEQ", "SUBEQ", "MULEQ", "DIVEQ", "INPUTSTREAM", 
                      "OUTPUTSTREAM", "PERIOD", "COMMA", "LETTER", "DIGIT", 
                      "IDENTIFIER", "LINEENDING", "COMMENT", "CHARL", "NUMLITERAL" ]

    RULE_parameter = 0
    RULE_start = 1
    RULE_r_type = 2

    ruleNames =  [ "parameter", "start", "r_type" ]

    EOF = Token.EOF
    ATOI=1
    BOOL=2
    BLOCK=3
    BREAK=4
    CASE=5
    CLASS=6
    CHAR=7
    CIN=8
    COUT=9
    DEFAULT=10
    ELSE=11
    FALSE=12
    IF=13
    INT=14
    ITOA=15
    KXI2022=16
    LOCK=17
    MAIN=18
    NEW=19
    NULL=20
    OBJECT=21
    PUBLIC=22
    PRIVATE=23
    PROTECTED=24
    RETURN=25
    RELEASE=26
    STRING=27
    SPAWN=28
    SYM=29
    SET=30
    SWITCH=31
    THIS=32
    TRUE=33
    THREAD=34
    UNPROTECTED=35
    UNLOCK=36
    VOID=37
    WHILE=38
    WAIT=39
    WHITESPACE=40
    COLON=41
    SEMI=42
    LEFTBRACE=43
    RIGHTBRACE=44
    LEFTPARAN=45
    RIGHTPARAN=46
    LEFTBRACKET=47
    RIGHTBRACKET=48
    EQUALS=49
    ISEQUALTO=50
    NOTEQUAL=51
    GREATEREQUAL=52
    LESSEQUAL=53
    GREATERTHAN=54
    LESSTHAN=55
    AND=56
    OR=57
    ADD=58
    SUB=59
    MUL=60
    DIV=61
    PLUSEQ=62
    SUBEQ=63
    MULEQ=64
    DIVEQ=65
    INPUTSTREAM=66
    OUTPUTSTREAM=67
    PERIOD=68
    COMMA=69
    LETTER=70
    DIGIT=71
    IDENTIFIER=72
    LINEENDING=73
    COMMENT=74
    CHARL=75
    NUMLITERAL=76

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.9.2")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None




    class ParameterContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def r_type(self):
            return self.getTypedRuleContext(KXIParser.R_typeContext,0)


        def IDENTIFIER(self):
            return self.getToken(KXIParser.IDENTIFIER, 0)

        def getRuleIndex(self):
            return KXIParser.RULE_parameter

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterParameter" ):
                listener.enterParameter(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitParameter" ):
                listener.exitParameter(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitParameter" ):
                return visitor.visitParameter(self)
            else:
                return visitor.visitChildren(self)




    def parameter(self):

        localctx = KXIParser.ParameterContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_parameter)
        try:
            self.state = 8
            self._errHandler.sync(self)
            la_ = self._interp.adaptivePredict(self._input,0,self._ctx)
            if la_ == 1:
                self.enterOuterAlt(localctx, 1)
                self.state = 6
                self.r_type()
                pass

            elif la_ == 2:
                self.enterOuterAlt(localctx, 2)
                self.state = 7
                self.match(KXIParser.IDENTIFIER)
                pass


        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class StartContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def PUBLIC(self):
            return self.getToken(KXIParser.PUBLIC, 0)

        def PRIVATE(self):
            return self.getToken(KXIParser.PRIVATE, 0)

        def getRuleIndex(self):
            return KXIParser.RULE_start

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterStart" ):
                listener.enterStart(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitStart" ):
                listener.exitStart(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitStart" ):
                return visitor.visitStart(self)
            else:
                return visitor.visitChildren(self)




    def start(self):

        localctx = KXIParser.StartContext(self, self._ctx, self.state)
        self.enterRule(localctx, 2, self.RULE_start)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 10
            _la = self._input.LA(1)
            if not(_la==KXIParser.PUBLIC or _la==KXIParser.PRIVATE):
                self._errHandler.recoverInline(self)
            else:
                self._errHandler.reportMatch(self)
                self.consume()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class R_typeContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def VOID(self):
            return self.getToken(KXIParser.VOID, 0)

        def INT(self):
            return self.getToken(KXIParser.INT, 0)

        def CHAR(self):
            return self.getToken(KXIParser.CHAR, 0)

        def BOOL(self):
            return self.getToken(KXIParser.BOOL, 0)

        def IDENTIFIER(self):
            return self.getToken(KXIParser.IDENTIFIER, 0)

        def getRuleIndex(self):
            return KXIParser.RULE_r_type

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterR_type" ):
                listener.enterR_type(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitR_type" ):
                listener.exitR_type(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitR_type" ):
                return visitor.visitR_type(self)
            else:
                return visitor.visitChildren(self)




    def r_type(self):

        localctx = KXIParser.R_typeContext(self, self._ctx, self.state)
        self.enterRule(localctx, 4, self.RULE_r_type)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 12
            _la = self._input.LA(1)
            if not((((_la) & ~0x3f) == 0 and ((1 << _la) & ((1 << KXIParser.BOOL) | (1 << KXIParser.CHAR) | (1 << KXIParser.INT) | (1 << KXIParser.VOID))) != 0) or _la==KXIParser.IDENTIFIER):
                self._errHandler.recoverInline(self)
            else:
                self._errHandler.reportMatch(self)
                self.consume()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx





