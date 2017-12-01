CFLAGS=-Wall -Wextra -g

all : init prod conso clear

init: init.o dijkstra.o
init.o: init.c dijkstra.h
prod: prod.o  dijkstra.o
prod.o: prod.c dijkstra.h
conso: conso.o  dijkstra.o
conso.o: conso.c dijkstra.h
clear: clear.o dijkstra.o
clear.o: clear.c dijkstra.h

dijkstra.o: dijkstra.c dijkstra.h

clean:
	@rm init prod conso clear *.o dijkstra.o