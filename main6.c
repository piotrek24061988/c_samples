#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void graj(int ile, char * co)
{
	for(int i = 0; i < ile; i++)
	{
		printf("%s, ", co);
	}
}

void graj2(int ile, char * co)
{
	for(int i = 0; i < ile; i++)
	{
		printf("%s\n", co);
	}
}

//Ptr to functions
void orkiestra(void(*funct)(int, char *), char * strs[], int size)
{
	for(int i = 0; i < size; i++)
	{
		funct(2, strs[i]);
	}
	printf("\n");
}

int main(int argc, char * const argv[]) {
	
	char * Strs[] = {"Trutu tutu", "Bum bum", "Tiri riri", "Brzdek brzdek", "Dzyn dzyn"};
    
	orkiestra(graj, Strs, sizeof(Strs) / sizeof(char *));
	orkiestra(graj2, Strs, sizeof(Strs) / sizeof(char *));

    return 0;
}

