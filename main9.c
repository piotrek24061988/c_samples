#include <stdio.h>
#include <stdlib.h>

typedef int liczba;

//Struct
struct czlowiek {
	const char * nazwa;
	int wiek;
};

typedef struct {
	const char * nazwa;
	liczba wiek;
} czlow;

void wyswietl_wiek(struct czlowiek cz) {
	printf("wiek czlowieka %s to: %i\n", cz.nazwa, cz.wiek);
}

void wyswietl_czlow(czlow cz) {
	printf("wiek czlowieka %s to: %i\n", cz.nazwa, cz.wiek);
}

void urodziny(czlow * cz) {
	printf("urodziny czlowieka %s. Teraz ma od lat: %i\n", cz->nazwa, ++cz->wiek);
	printf("%s imprezuje\n", (*cz).nazwa);
}

int main(int argc, char * const argv[]) {

	struct czlowiek albinos = {"Rysio", 49};
	wyswietl_wiek(albinos);
	
	czlow albinos2 = {"Rysiek", 49};
	wyswietl_czlow(albinos2);
	
	urodziny(&albinos2);
	wyswietl_czlow(albinos2);

    return 0;
}

