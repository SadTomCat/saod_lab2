main: ./built/gen_and_hash.o ./built/bstree.o ./built/hashtab.o ./built/main.o 
	gcc -o ./bin/main ./built/gen_and_hash.o  ./built/bstree.o ./built/hashtab.o  ./built/main.o 
	 
./built/gen_and_hash.o: ./src/gen_and_hash.c
	gcc -o ./built/gen_and_hash.o -c ./src/gen_and_hash.c

./built/main.o: ./src/main.c
	gcc -o ./built/main.o -c ./src/main.c

./built/bstree.o: ./src/bstree.c
	gcc -o ./built/bstree.o -c ./src/bstree.c

./built/hashtab.o: ./src/hashtab.c
	gcc -o ./built/hashtab.o -c ./src/hashtab.c

./built/generation.o: ./src/generation.c
	gcc -o ./built/generation.o -c ./src/generation.c

run: ./bin/main
	./bin/main

clean:
	rm ./bin/main 

clean_o: 
	rm ./built/*
