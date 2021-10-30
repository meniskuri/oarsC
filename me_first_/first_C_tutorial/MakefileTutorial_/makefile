CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

hellomake: hellomake.o hellofunc.o
	$(CC) -o hellomake hellomake.o hellofunc.o

hellomake.o: hellomake.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
