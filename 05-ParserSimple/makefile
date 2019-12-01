

Parser: Parser.o StackOfCharsModule.o
	gcc Parser.o StackOfCharsModule.o -Wall -g -o Parser

StackOfCharsModule.o: StackOfCharsModule.c StackOfCharsModule.h
	gcc -c StackOfCharsModule.c

clean: 
	rm *.o Parser
