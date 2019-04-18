main: ./built/hash.o ./built/bstree.o ./built/hashtab.o ./built/main.o 
	gcc -o ./bin/main ./built/hash.o  ./built/bstree.o ./built/hashtab.o  ./built/main.o 
	 
./built/hash.o: ./src/hash.c
	gcc -o ./built/hash.o -c ./src/hash.c

./built/main.o: ./src/main.c
	gcc -o ./built/main.o -c ./src/main.c

./built/bstree.o: ./src/bstree.c
	gcc -o ./built/bstree.o -c ./src/bstree.c

./built/hashtab.o: ./src/hashtab.c
	gcc -o ./built/hashtab.o -c ./src/hashtab.c

run: ./bin/main
	./bin/main

clean:
	rm ./bin/main 

clean_o: 
	rm ./built/*
