#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char * const argv[]) {
	
	char napis1[] = "dzieci wesolo wybiegly ze szkoly,";
	char napis2[] = "zapalily papierosy, wyciagnely flaszki.";
	
	char * znak;
	char litera = 'd';
	if(znak = strchr(napis1, litera))
	{
		printf("litera: %c znajduje sie pod adresem %p w napisie: %s ktory ma %d znakow\n", *znak, znak, napis1, strlen(napis1));
	}
	else {
		printf("litery: %c nie ma w napisie: %s ktory ma %d znakow\n", litera, napis1, strlen(napis1));
	}
	
	if(znak = strchr(napis2, litera))
	{
		printf("litera: %c znajduje sie pod adresem %p w napisie: %s, ktory ma %d znakow\n", *znak, znak, napis2, strlen(napis2));
	}
	else {
		printf("litery: %c nie ma w napisie: %s ktory ma %d znakow\n", litera, napis2, strlen(napis2));
	}
	
	char * tekst;
	char * napis = "wesolo";
	if(tekst = strstr(napis1, napis))
	{
		printf("napis: %s znajduje sie pod adresem %p w napisie: %s ktory ma %d znakow\n", napis, tekst, napis1, strlen(napis1));
	}
	else {
		printf("napisu: %s nie ma w napisie: %s ktory ma %d znakow\n", napis, napis1, strlen(napis1));
	}
	if(tekst = strstr(napis2, napis))
	{
		printf("napis: %s znajduje sie pod adresem %p w napisie: %s, ktory ma %d znakow\n", napis, tekst, napis2, strlen(napis2));
	}
	else {
		printf("napisu: %s nie ma w napisie: %s ktory ma %d znakow\n", napis, napis2, strlen(napis2));
	}
	
	char * napis3 = strcat(napis2, napis);
	if(znak = strchr(napis3, litera))
	{
		printf("litera: %c znajduje sie pod adresem %p w napisie: %s ktory ma %d znakow\n", *znak, znak, napis3, strlen(napis3));
	}
	else {
		printf("litery: %c nie ma w napisie: %s ktory ma %d znakow\n", litera, napis3, strlen(napis3));
	}
	
	if(znak = strchr(napis3, litera))
	{
		printf("litera: %c znajduje sie pod adresem %p w napisie: %s, ktory ma %d znakow\n", *znak, znak, napis3, strlen(napis3));
	}
	else {
		printf("litery: %c nie ma w napisie: %s ktory ma %d znakow\n", litera, napis3, strlen(napis3));
	}
	
	if(tekst = strstr(napis3, napis))
	{
		printf("napis: %s znajduje sie pod adresem %p w napisie: %s ktory ma %d znakow\n", napis, tekst, napis3, strlen(napis3));
	}
	else {
		printf("napisu: %s nie ma w napisie: %s ktory ma %d znakow\n", napis, napis1, strlen(napis1));
	}
	if(tekst = strstr(napis3, napis))
	{
		printf("napis: %s znajduje sie pod adresem %p w napisie: %s, ktory ma %d znakow\n", napis, tekst, napis3, strlen(napis3));
	}
	else {
		printf("napisu: %s nie ma w napisie: %s ktory ma %d znakow\n", napis, napis2, strlen(napis2));
	}
		

    return 0;
}

