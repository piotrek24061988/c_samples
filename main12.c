#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * wykonaj(void *a)
{
	for(int i = 0; i < 5; i++) {
		sleep(1);
		printf("wykonaj1: %d\n", i);
	}
}

int main(int argc, char * const argv[]) {

	printf("start\n");
	wykonaj(NULL);
	
	
	pthread_t t0, t1;
	if(pthread_create(&t0, NULL, wykonaj, NULL) == -1) {
		printf("Nie mozna utworzyc watku: %d\n", t0);
	} else {
		printf("Watek: %d utworzony\n", t0);
	}
	if(pthread_create(&t1, NULL, wykonaj, NULL) == -1) {
		printf("Nie mozna utworzyc watku: %d\n", t0);
	} else {
		printf("Watek: %d utworzony\n", t0);
	}
	
	void * results;
	if(pthread_join(t0, results) == -1) {
		printf("Nie mozna zakonczyc watku: %d\n", t0);
	} else {
		printf("Watek: %d zakonczony\n", t0);
	}
	if(pthread_join(t1, results) == -1) {
		printf("Nie mozna zakonczyc watku: %d\n", t1);
	} else {
		printf("Watek: %d zakonczony\n", t1);
	}

    return 0;
}