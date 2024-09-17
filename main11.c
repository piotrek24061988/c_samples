#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1 direction list
typedef struct czlowiek {
	char * nazwa;
	int wiek;
	struct czlowiek * nastepny;
} czlowiek;

void wyswietl_wszystko(czlowiek *cz) {
	if(!cz) {
		printf("wyswietl_wszystko input arg (czlowiek * NULL)\n");
		return;
	}
	czlowiek *i = cz;
	for(; i!= NULL; i = i->nastepny) {
		printf("Nazwa: %s, wiek: %i \n", i->nazwa, i->wiek);
	}
	printf("\n");
}

//malloc example
czlowiek * stworz(char * nazwa, int wiek) {
	czlowiek *i = malloc(sizeof(czlowiek));
	i->nazwa = strdup(nazwa);
	i->wiek = wiek;
	i->nastepny = NULL;
	return i;
}

//free example
void czysc(czlowiek * cz) {
	czlowiek *i = cz;
	czlowiek * nastepny = NULL;
	for(; i != NULL; i = nastepny) {
		nastepny = i->nastepny;
		free(i->nazwa);
		free(i);
		i = NULL;	
	}
}

int main(int argc, char * const argv[]) {
	czlowiek pierwszy = {"Rysio", 49};
	czlowiek drugi = {"Misio", 33};
	czlowiek trzeci = {"Zuzia", 21};
	
	pierwszy.nastepny = &drugi;
	drugi.nastepny = &trzeci;
	trzeci.nastepny = NULL;
	
	wyswietl_wszystko(&pierwszy);
	
	czlowiek * czwarty = stworz("Henio", 15);
	czlowiek * piaty = stworz("Ala", 16);
	czlowiek * szusty = stworz("Kaziu", 17);
	
	czwarty->nastepny = piaty;
	piaty->nastepny = szusty;
	szusty->nastepny = NULL;
	
	wyswietl_wszystko(czwarty);
	czysc(czwarty);
	czwarty = piaty = szusty = NULL;
	wyswietl_wszystko(czwarty);

    return 0;
}