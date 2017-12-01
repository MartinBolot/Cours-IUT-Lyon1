#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <sys/types.h>

/* Creation */
int sem_create(key_t cle, int initval);


/* Suppression */
void sem_delete(int semid);

/* P */
void P(int semid);

/* V */
void V(int semid);

#endif