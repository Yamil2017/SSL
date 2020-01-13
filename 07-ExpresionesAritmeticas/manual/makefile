

Calculator: calc.o Scanner.o StackOfDoublesModule.o
	gcc calc.o Scanner.o StackOfDoublesModule.o -Wall -g -o calc

Scanner.o: Scanner.o
	gcc -c Scanner.c

StackOfDoublesModule.o: StackOfDoublesModule.c StackOfDoublesModule.h
	gcc -c StackOfDoublesModule.c

clean: 
	rm *.o calc
