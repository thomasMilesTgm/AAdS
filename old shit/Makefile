CC = gcc
CFLAGS = -Wall -pedantic

imdb: bst.o
	$(CC) -o $(CFLAGS) bst.o

bst.o : main2015.c header2015.h
	$(CC) -c $(CFLAGS) main2015.c

clean :
	rm -f *.o *~ ${PROGRAM}
