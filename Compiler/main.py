# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import sys

from antlr4 import *
from gen.KXILexer import KXILexer
from gen.KXIParser import KXIParser
from gen.KXILexer import ParseTreeWalker


# Press the green button in the gutter to run the script.
def main():
    tokens = dict()
    a_file = open("C:\Compiler\gen\KXI.tokens")
    for line in a_file:
        mine = line.strip()
        key, value = mine.rsplit('=')
        tokens[key] = value


    input1 = InputStream('/')
    lexer = KXILexer(input1)
    stream = CommonTokenStream(lexer)
    stream.fill()
    parser = KXIParser(stream)
    uy = parser.getCurrentToken()
    
    #print(uy.line, uy.text, uy.type)
    #print(dir(uy))
    uy = stream.fill()

    # tree = parser.startRule()


if __name__ == '__main__':
    main()
