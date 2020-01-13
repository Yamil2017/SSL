
wordCounter: source.o iofunc.o
	gcc source.o iofunc.o -g -Wall -o wordCounter

source.o: source.c
	gcc -c source.c

iofunc.o: iofunc.c
	gcc -c iofunc.c

clean: 
	rm *.o wordCounter
