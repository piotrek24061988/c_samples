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
	int i;
	for(i = 0; inputString[i]; i++) {
		outputString[i] = tolower(inputString[i]);
	}
	outputString[i] = '\0';
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

	char prevChar = 0;//a
	int counter = 0;//1
	char buffer[10];
	sprintf(buffer, "");
	
	for(int i = 0; inputString[i]; i++)
	{
		if(inputString[i] != prevChar) {
			//first sign
			if(prevChar == 0) {
				prevChar = inputString[i];
				counter = 1;		
			}
			//new sign
			else {
				sprintf(buffer, "%i", counter);
				strcat(outputString, buffer);
				sprintf(buffer, "%c", prevChar);
				strcat(outputString, buffer);
				
				counter = 1;
				prevChar = inputString[i];
			}
		}
		//the same sign
		else if(inputString[i] == prevChar) {
			counter++;
		}
	}
	if((prevChar != 0) && (counter != 0)) {
		sprintf(buffer, "%i", counter);
		strcat(outputString, buffer);
		sprintf(buffer, "%c", prevChar);
		strcat(outputString, buffer);
		strcat(outputString, "\0");
	}
}


//
// Perform decoding
//
void decode(const char * inputString, char * outputString) {
	
	int value = 0;
	char currChar = 0;
	
	printf("decode: input string: %s\n", inputString);

	for(int i = 0; inputString[i]; i = i+2) {
		if(inputString[i+1] == '\0')
			return;
		//read number
		sscanf(&inputString[i], "%*[^0123456789]%d", &value);
		printf("  value[%i]:%i\n", i, value);
		//read sign
		sscanf(&inputString[i+1], "%*[^abcdefghijklmnopqrstuvwqyz]%c", &currChar);
		printf("  currChar[%i]:%c\n", i, currChar);
		
		for(int j = 0; j < value; j++){
			strncat(outputString, &currChar, 1);
		}
	}
}

int main(int argc, const char * argv[]) {
	
	//Check input
	if(isInputStringProvided(argc, argv) == -1) {
		return -1;
	} 
	
	//Create buffers
	char inStr[strlen(argv[1])];
	char outStr[strlen(argv[1])];
	char outStr2[strlen(argv[1])];
	sprintf(outStr2, "%c", '\0');
	
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
	printf("Encoded input is: %s\n", outStr);
	
	//Decode back
	if(outStr) {
		printf("Lets decode back: \n");
	}
	decode(outStr, outStr2);
	printf("Input decoded back is: %s\n", outStr2);

    return 0;
}