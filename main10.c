#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//metaprograming
#define SWAP(A, B) { typeof(A) C; C = A; A = B; B = C; } 

//function with flexible number of input arguments
void wyswietl(int args, ...) {
	//list to store additional function arguments
	va_list list;
	               //last named argument of the function
	va_start(list, args); //initialize list with all additional function arguments
	
	va_list list2;
	va_copy(list2, list);	
	
	for(int i = 0; i < args; i++) {               //retrieve element from the list which is int type in this example
		printf("argument: %i ma wartosc %i, ", i, va_arg(list, int));
	}
	printf("\n");
	
	
	for(int i = 0; i < args; i++) {               
		printf("jeszcze raz - argument: %i ma wartosc %i, ", i, va_arg(list2, int));
	}
	printf("\n");
	
	va_end(list);//cleanup for va_start 
	va_end(list2);//cleanup for va_start 
}

int main(int argc, char * const argv[]) {

	wyswietl(3, 4, 5, 6);
	
	int a = 1, b = 2;
	printf("a: %i, b: %i\n", a, b);
	SWAP(a, b);
	printf("a: %i, b: %i\n", a, b);
	
	float c = 3.14, d = 6.28;
	printf("c: %.2f, d: %.2f\n", c, d);
	SWAP(c, d);
	printf("c: %.2f, d: %.2f\n", c, d);

    return 0;
}

