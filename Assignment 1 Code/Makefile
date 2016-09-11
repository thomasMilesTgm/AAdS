# Written by Thomas Miles (626263)
# Last modified 10/09/16

CC = gcc
CFLAGS = -Wall -pedantic

yelp_1: yelp_1.o dict_1.o
	$(CC) $(CFLAGS) -o yelp_1 yelp_1.o dict_1.o bst_1.o

yelp_1.o:  yelp_1.c dict_1.o bst_1.o
	$(CC) -c $(CFLAGS) yelp_1.c

dict_1.o: dict_1.c dict_1.h bst_1.o
	$(CC) -c $(CFLAGS) dict_1.c

bst_1.o: bst_1.c bst_1.h
	$(CC) -c $(CFLAGS) bst_1.c
