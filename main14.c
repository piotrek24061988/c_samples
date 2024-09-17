#include <stdio.h>
#include <string.h>
#include <ctype.h>

//
// Check is program args contains string to encode
//
int isInputStringProvided(int argc, const char * argv[]) {
	if(argc < 2) {
		printf("no input sting to encode\n");
		return -1;
	}
	else if(argc > 2) {
		printf("please provide 1 input string to encode\n");
		return -1;	
	}
	return 0;
}

//
// Check is string to encode is correct and adjust it for further processing
//
int isInputStringCorrect(const char * inputString, char * outputString) {
	//Convert input letters to low letters
	for(int i = 0; inputString[i]; i++) {
		outputString[i] = tolower(inputString[i]);
	}
	//Check if there are only letters in string
	for(int i = 0; inputString[i]; i++) {
		if( (outputString[i] < 'a') || (outputString[i] > 'z')) {
			printf("please provide input string containing only letters\n");
			outputString = NULL;
			return -1;
		}
	}
	
	return 0;
}

//
// Perform encoding
//
void encode(const char * inputString, char * outputString) {
	char prevChar = 0;
	int counter = 0;
	char count[10];
	
	for(int i = 0; inputString[i]; i++) {
		if(inputString[i] == prevChar) {
			counter++;
		} else { 
			if(prevChar != 0) {
				sprintf(count, "%d", counter);
				strcat(outputString, count);
				sprintf(count, "%c", prevChar);
				strncat(outputString, count, 1);
			}
			prevChar = inputString[i];
			counter = 1;
		}
	}
	sprintf(count, "%d", counter);
	strcat(outputString, count);
	sprintf(count, "%c", prevChar);
	strncat(outputString, count, 1);
}

int main(int argc, const char * argv[]) {
	
	//Check input
	if(isInputStringProvided(argc, argv) == -1) {
		return -1;
	} 
	
	//Create buffers
	char inStr[strlen(argv[1])];
	char outStr[strlen(argv[1])];
	strcpy(outStr, "");
	
	//Preprocess input
	if(isInputStringCorrect(argv[1], inStr) == -1) {
			printf("problems with input string");
			return -1;			
	} 
	
	//Encode
	if(inStr) {
		printf("input string to encode is %s\n", inStr);
		printf("Lets encode: \n");
	}
	encode(inStr, outStr);
	
	//Print output
	printf("Encoded input is: %s\n", outStr);

    return 0;
}