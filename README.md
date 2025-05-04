# TPL-CCP

bison -d c_parser.y
flex c_lexer.l
gcc -Wall -g -o c_compiler.exe lex.yy.c c_parser.tab.c

c_compiler.exe simple_test.c
