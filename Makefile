main: ./built/bstree.o ./built/hashtab.o ./built/main.o
	gcc -o main ./bin/bstree.o ./bin/hashtab.o ./bin/main.o

./built/bstree.o: ./src/bstree.c
	gcc -o ./built/bstree.o ./src/bstree.c

./built/hashtab.o: ./src/hashtab.c
	gcc -o ./built/hashtab.o ./src/hashtab.c

./built/main.o: ./src/main.c
	gcc -o ./built/main.o ./src/main.c

./built/clean:
	rm ./bin/main
