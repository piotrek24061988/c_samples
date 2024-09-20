#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(A, B) { typeof(A) C; C = A; A = B; B = C; } 

void babSort(const char * in, char * out) {
	
	strcpy(out, in);
	
	for(int i = 0; i < strlen(out); i++){
		for(int j = 0; j < strlen(out) - i - 1; j++)
			if(out[j] > out[j + 1]) {
				SWAP(out[j], out[j + 1]);
			}
	}
}

int main(int argc, const char * argv[]) {
	
	if(argc <= 1) {
			return 0;
	}
	
	const char * toSort = argv[1];
	char sorted[strlen(toSort)];
	sprintf(sorted, "%s", '\0');
	
	printf("Input string is: %s\n", toSort);
	babSort(toSort, sorted);

	printf("Output string is: %s\n", sorted);

    return 0;
}