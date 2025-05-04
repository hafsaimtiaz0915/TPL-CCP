# TPL-CCP

bison -d c_parser.y
flex c_lexer.l
gcc -Wall -g -o c_compiler.exe lex.yy.c c_parser.tab.c

c_compiler.exe simple_test.c


report link 
https://docs.google.com/document/d/1hoNyk6UeFu9EHf0seE_ig18rnCIFp-8fIpcmVt16LPU/edit?usp=sharing
