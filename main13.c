#include <stdio.h>
#include <unistd.h>

int main(int argc, char * const argv[]) {
	
	FILE *fp1, *fp2;
	char buffer[50];
	char buffer2[50];
	char znak;
	
	fp1 = fopen("./dane1.txt", "r");
	if(fp1 == NULL) {
		printf("problem z plikiem wejsciowym \n");
		return 0;
	}
	fscanf(fp1, "%s", buffer);
	printf("dane odczytane z pliku: %s\n", buffer);
	
	fgets(buffer2, 50, fp1);
	printf("dane odczytane z pierwszej lini: %s\n", buffer2);
	
	fp2 = fopen("./tekst1.txt", "w");
	if(fp2 == NULL) {
		printf("problem z plikiem wyjsciowym \n");
	}
	fprintf(fp2, "dane zapisane fprintf: %s\n", buffer);
	fprintf(fp2, "dane zapisane z calej lini:\n");
	fputs(buffer2, fp2);
	
	printf("dane odczytane i zapisane znak po znaku:\n");
	fprintf(fp2, "dane zapisane znak po znaku:\n");
	while(znak != EOF) {
		znak = fgetc(fp1); // czytanie po znaku;
		fputc(znak, fp2);
		printf("%c", znak);
	}
	
	fclose(fp1);
	fclose(fp2);

    return 0;
}