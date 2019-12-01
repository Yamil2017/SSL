

Calculator: Parser.o StackOfCharsModule.o
	gcc Parser.o StackOfCharsModule.o -Wall -g -o Parser

StackOfDoublesModule.o: StackOfCharsModule.c StackOfCharsModule.h
	gcc -c StackOfCharsModule.c

clean: 
	rm *.o Parser
