
all:
	lex Scanner.l
	yacc -d Parser.y
	gcc lex.yy.c y.tab.c -Wall -g -o calc.out

clean: 
	rm *.o *.out
