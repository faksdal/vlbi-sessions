 
CC=gcc
CFLAGS=-I.
OBJ = obj/htmlparser.o

all: $(OBJ)
	$(CC) $(OBJ) -o htmlparser

obj/htmlparser.o: htmlparser.c
	$(CC) $(CFLAGS) -c -o obj/htmlparser.o htmlparser.c


clean:
	rm -rf obj/*.o

