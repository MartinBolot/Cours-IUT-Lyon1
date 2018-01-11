#CFLAGS= -lpthread -Wall -Wextra -g
CFLAGS=-lpthread
LFLAGS=-pthread

all : ex1

ex1: ex1.o dijkstra.o
	gcc -o ex1 ex1.o -lpthread
ex1.o: ex1.c dijkstra.h

dijkstra.o: dijkstra.c dijkstra.h

clean:
	@rm ex1 *.o dijkstra.o