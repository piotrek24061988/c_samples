#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char * const argv[]) {
	
	FILE * wej = fopen("dane.txt", "r");
	FILE * wyj = fopen("wyj.txt", "w");
	FILE * err = fopen("err.txt", "w");
	
	float dane;
	int number1 = fileno(wej);
	int number2 = fileno(wyj);
	int number3 = fileno(err);
	
	printf("Numer deskryptora dla pliku dane.txt: %i, \n", number1);
	printf("Numer deskryptora dla pliku wyj.txt: %i, \n", number2);
	printf("Numer deskryptora dla pliku err.txt: %i, \n", number3);
	
	dup2(number1, 0);
	dup2(number2, 1);
	dup2(number3, 2);
	
	scanf("%f", &dane);
	fprintf(stderr, "dane ze strumienia wej dla strumienia error to: %f\n", dane);
	fprintf(stdout, "dane ze strumienia wej dla strumienia wyjsciowego to: %f\n", dane);
	
	fclose(wej);
	fclose(wyj);
	fclose(err);

    return 0;
}

