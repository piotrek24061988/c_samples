#include <stdio.h>

void overwrite(int * wsk, int var) {
	*wsk = var; 
}

//pointers
int main(int argc, char * const argv[]) {
    
	int var1 = 3;
	printf("adres zmiennej: %p, wartosc zmiennej: %d\n", &var1, var1);
	
	int * wsk1 = &var1;
	printf("adres zmiennej: %p, wartosc zmiennej: %d\n", wsk1, *wsk1);
	
	overwrite(&var1, 5);
	printf("adres zmiennej: %p, wartosc zmiennej: %d\n", &var1, var1);
	
	overwrite(wsk1, 6);
	printf("adres zmiennej: %p, wartosc zmiennej: %d\n", wsk1, *wsk1);
	
	char tab[2] = {'a', 'b'};
	char * wsk = tab;
	
	printf("pokazywane wskaznikiem:\n");
	printf("adres 1 elementu w pamieci to: %p\n", wsk);
	printf("wartosc 1 elementu w pamieci to: %c\n", *wsk);
	printf("rozmiar adresu 1 elementu w pamieci to: %p\n", sizeof(wsk));
	printf("rozmiar 1 elementu w pamieci to: %p\n", sizeof(*wsk));
	printf("adres 2 elementu w pamieci to: %p\n", wsk + 1);
	printf("wartosc 2 elementu w pamieci to: %c\n", *(wsk + 1));
	printf("rozmiar adresu 2 elementu w pamieci to: %p\n", sizeof(wsk + 1));
	printf("rozmiar 2 elementu w pamieci to: %p\n", sizeof(*(wsk + 1)));
	
	printf("pokazywane tablica\n");
	printf("adres 1 elementu w pamieci to: %p\n", tab);
	printf("wartosc 1 elementu w pamieci to: %c\n", tab[0]);
	printf("rozmiar tablicy: %p\n", sizeof(tab));
	printf("rozmiar adresu 1 elementu w pamieci to: %p\n", sizeof(&tab[0]));
	printf("rozmiar 1 elementu w pamieci to: %p\n", sizeof(tab[0]));
	printf("adres 2 elementu w pamieci to: %p\n", &tab[1]);
	printf("wartosc 2 elementu w pamieci to: %c\n", tab[1]);
	printf("rozmiar adresu 2 elementu w pamieci to: %p\n", sizeof(&tab[1]));
	printf("rozmiar 2 elementu w pamieci to: %p\n", sizeof(tab[1]));
	
	char chartab[] = "avrkwiat";
	puts(chartab);
	chartab[0] = 'A';
	puts(chartab);
	
	const char *wsktab = "avtkwiat";
	puts(wsktab);
	//pointer to const char which cant be updated
	//wsktab[0] = 'A';
	//puts(wsktab);

    return 0;
}

