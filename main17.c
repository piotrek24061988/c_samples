#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

void * func(void *a)
{
	static int i = 0;
	int j = 0;
	
	int * k = malloc(sizeof(int));
	
	printf("adress for data in globals: %p\n", &i);//variable on thread private stack memory area
	printf("adress for data on stuck: %p\n", &j);//variable in threads common globals memory area
	printf("adress for data in heap: %p\n\n", k);//variable in threads common heap memory area
	
	free(k);
}


int main(int argc, const char * argv[]) {
	
	pthread_t t0, t1;
	void * results;

	pthread_create(&t0, NULL, func, NULL);
	pthread_join(t0, results);
	
	pthread_create(&t1, NULL, func, NULL);
	pthread_join(t1, results);
}