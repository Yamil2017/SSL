
wordCounter: wordCounter.o binaryTree.o getword.o
	gcc wordCounter.o binaryTree.o getword.o -g -Wall -o wordCounter

wordCounter.o: wordCounter.c
	gcc -c wordCounter.c

binaryTree.o: binaryTree.c
	gcc -c binaryTree.c

getword: getword.c
	gcc -c getword.c

clean: 
	rm *.o wordCounter
