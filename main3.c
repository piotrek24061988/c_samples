#include <stdio.h>

#define Tab1Size 5

//functions
void printTableI(int tab[], int size)
{
	for(int i = 0; i < size; i++) {
		printf("%d\n", tab[i]);
	}
	printf("\n");
}

void printTableD(double tab[], int size)
{
	for(int i = 0; i < size; i++) {
		printf("%f.2\n", tab[i]);
	}
	printf("\n");
}

void printTableI2(int tab[][Tab1Size], int size) 
{
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			printf("%d", tab[i][j]);
	printf("\n");
}

int main(int argc, char * const argv[]) {
    
	//tabs
	int tab1[Tab1Size];
	tab1[0] = 0; tab1[1] = 1; tab1[2] = 2;
	
	double tab2[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9};
	
	printTableI(tab1, Tab1Size);
	printTableD(tab2, 8);
	
	int tab[Tab1Size][Tab1Size] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}, {4, 5, 6, 7, 8}, {5, 6, 7, 8, 9}};
	printTableI2(tab, Tab1Size);
	
	//pointers
	int * wsk = tab1;
	printf("%ld\n", tab1);	
	printf("%ld\n", tab1[0]);
	printf("%ld\n", wsk);
	printf("%ld\n", *wsk);
    
    return 0;
}

