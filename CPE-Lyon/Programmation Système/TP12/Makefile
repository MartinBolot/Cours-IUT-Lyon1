CFLAGS= -lpthread -Wall -Wextra -g
LFLAGS=-pthread

all : ex1

ex1: ex1.o dijkstra.o
	#gcc -o ex1 ex1.o -lpthread
	#gcc -o dijkstra dijkstra.o
ex1.o: ex1.c dijkstra.h

dijkstra.o: dijkstra.c dijkstra.h

clean:
	@rm ex1 *.o dijkstra.o