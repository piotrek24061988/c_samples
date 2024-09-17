#include <stdio.h>

int main(int argc, char * const argv[]) {
    
	char tab[40];
	int liczba = 10;
	
	//printf sprintf
	printf("tab: %s\n", tab);
	sprintf(tab, "Liczba: %d\n", liczba);
	printf("tab: %s\n", tab);
	
	//scantf
	int x, y;
	printf("podaj 2 liczby calkowite: ");
	scanf("%d %d", &x, &y);
	printf("ich suma wynosci: %d\n", x+y);
	
	double a, b;
	printf("podaj 2 liczby rzeczywiste: ");
	scanf("%lf", &a);
	scanf("%lf", &b);
	//scanf("%f %f", &a, &b);
	printf("ich suma wynosci: %f + %f = %f\n", a, b, a+b);
	
	//sscanf
    const char input[] = "Grobla 8 / 10";
    char street[20];
    int flatNr;
    char separator;
    int houseNr;

    int result = sscanf(input, "%s %d %c %d", street, &flatNr, &separator, &houseNr);

    printf("Ulica: %s, nr bloku: %d, nr mieszkania: %d", street, flatNr, houseNr);

    return 0;
}

