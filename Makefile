 
CC=g++
CFLAGS=-I.
OBJ = obj/htmlparse.o obj/htmlparser.o

all: $(OBJ)
	$(CC) $(OBJ) -o htmlparser

obj/htmlparse.o: htmlparse.cpp
	$(CC) $(CFLAGS) -c -o obj/htmlparse.o htmlparse.cpp

obj/htmlparser.o: htmlparser.cpp
	$(CC) $(CFLAGS) -c -o obj/htmlparser.o htmlparser.cpp


clean:
	rm -rf obj/*.o

