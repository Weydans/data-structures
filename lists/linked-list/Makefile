CC=gcc
FLAGS=-Wall -g 
INCLUDE=-I./include
SOURCE=source/linked-list.c
VALGRIND=valgrind --leak-check=full

all:
	$(CC) $(FLAGS) $(INCLUDE) $(SOURCE) test/test.c -o test-linked-list

test:
	$(VALGRIND) ./test-linked-list

clear:
	rm -rf main test-linked-list
