a.out: main.o arbol.o
	gcc main.o arbol.o
main.o: main.c
	gcc -c main.c
arbol.o: arbol.c
	gcc -c arbol.c
run: a.out
	./a.out
clear:
	rm a.out main.o arbol.o 
