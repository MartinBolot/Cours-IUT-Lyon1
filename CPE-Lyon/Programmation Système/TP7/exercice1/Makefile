all : init p1 p2 detruire

init: init.o ../dijkstra.o
	gcc -o init init.o

init.o: init.c ../dijkstra.c
	gcc -o init.o -c init.c -Wall

p1: p1.o ../dijkstra.o
	gcc -o p1 p1.o

p1.o: p1.c ../dijkstra.c
	gcc -o p1.o -c p1.c -Wall

p2: p2.o ../dijkstra.o
	gcc -o p2 p2.o

p2.o: p2.c ../dijkstra.c
	gcc -o p2.o -c p2.c -Wall

detruire: detruire.o ../dijkstra.o
	gcc -o detruire detruire.o

detruire.o: detruire.c ../dijkstra.c
	gcc -o detruire.o -c detruire.c -Wall
	