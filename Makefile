all: run

lista.o: lista.c
	gcc -c lista.c
pilha.o: pilha.c
	gcc -c pilha.c
fila.o: fila.c
	gcc -c fila.c
main.o: main.c
	gcc -c main.c
lista.x: main.o lista.o pilha.o fila.o
	gcc -o lista.x main.o lista.o pilha.o fila.o
run: lista.x
	./lista.x
clean:
	rm -f *.o *.x
