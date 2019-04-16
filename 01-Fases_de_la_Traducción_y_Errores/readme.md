1. Investigar las funcionalidades y opciones que su compilador presenta para
limitar el inicio y fin de las fases de traducción.
2. Para la siguiente secuencia de pasos:
a. Transicribir en readme.md cada comando ejecutado y
b. Describir en readme.md el resultado u error obtenidos para cada paso.

gcc -E -Wall hello2.c -o hello2.i -Sin errores-
gcc -E -Wall hello3.c -o hello3.i -Sin errores-
gcc -S -Wall hello3.c -o hello3.s 
	Warning-implicit declaration of function 'prontf'; did you mean 'printf'?-
	Warning-unused variable 'i'-
	Error-expected declaration or statement at end of input-
gcc -S -Wall hello4.c -o hello4.s 
	Warning-format '%d' expects a matching 'int' argument-
gcc -c -Wall hello.c -o hello4.o-sin errores-
gcc -Wall -Lstdlib hello4.o -o hello4.exe
	error-undefined reference to 'prontf'-
