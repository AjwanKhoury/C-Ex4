CC=gcc
AR=ar

FLAGS= -Wall -g

all:frequency

frequency:main.o trie.o libmylib.a
	$(CC) $(FLAGS) -o frequency main.o trie.o libmylib.a

libmylib.a: trie.o trie.h
	$(AR) -rsc libmylib.a trie.o trie.h

main.o: main.c trie.h
	$(CC) $(FLAGS) -c main.c

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

.PHONY: clean all

clean:
	rm -f *.o *.a frequency		