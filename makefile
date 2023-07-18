CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -Wno-unused-but-set-variable

banker: banker.o
	$(CC) $(CFLAGS) -o banker banker.o

banker.o: banker.c
	$(CC) $(CFLAGS) -c banker.c

clean:
	rm -f banker.o banker