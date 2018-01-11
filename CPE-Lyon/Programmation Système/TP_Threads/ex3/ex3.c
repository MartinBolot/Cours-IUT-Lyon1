#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t verrou1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t verrou2 = PTHREAD_MUTEX_INITIALIZER;

// traitement 1
void *T1(void *arg) {
	pthread_mutex_unlock(&verrou1);
	printf("traitement 1");
	pthread_mutex_lock(&verrou2);
}

// traitement 2
void *T2(void *arg) {
	pthread_mutex_unlock(&verrou2);
	printf("traitement 2");
	pthread_mutex_lock(&verrou1);
}

int main() {
	pthread_t thread1, thread2;
	void *returnValue;
	
	pthread_mutex_lock(&verrou1);
	pthread_mutex_lock(&verrou2);
	
	/*
	if (
		pthread_create(&thread1, NULL, T1, NULL)
		&& pthread_create(&thread2, NULL, T2, NULL)
	) {
		pthread_join(thread1, &returnValue);
		pthread_join(thread2, &returnValue);
	}
	*/
	pthread_create(&thread1, NULL, T1, NULL);
	pthread_create(&thread2, NULL, T2, NULL);
	pthread_join(thread1, &returnValue);
	pthread_join(thread2, &returnValue);
	
	return 0;
}