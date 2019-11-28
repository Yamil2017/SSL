
all:
	lex Scanner.l
	yacc -d Parser.y
	gcc lex.yy.c y.tab.c -Wall -g -o calc

clean: 
	rm *.o calc lex.yy.c y.tab.c y.tab.h
