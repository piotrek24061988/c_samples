#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void * dec(void *a)
{
	long int * c = a;
	for(long int i = 0; i < 10000000; i++) {
		pthread_mutex_lock(&mut);
		*c = *c - 1;
		pthread_mutex_unlock(&mut);
	}
}

void * inc(void *a)
{
	long int * c = a;
	for(long int i = 0; i < 10000000; i++) {
		pthread_mutex_lock(&mut);
		*c = *c + 1;
		pthread_mutex_unlock(&mut);
	}
}

int main(int argc, char * const argv[]) {
	
	long int licznik = 20000000;
	
	printf("start: %i\n", licznik);
	
	pthread_t t0, t1;
	if(pthread_create(&t0, NULL, dec, &licznik) == -1) {
		printf("Nie mozna utworzyc watku: %d\n", t0);
	} else {
		printf("Watek: %d utworzony\n", t0);
	}
	if(pthread_create(&t1, NULL, inc, &licznik) == -1) {
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
	
	printf("end: %i\n", licznik);

    return 0;
}