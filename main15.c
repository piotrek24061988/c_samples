#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void myStrCpy1(const char *inStr, char * outStr) {
	
	for(int i = 0;;i++) {
		outStr[i] = inStr[i];
		
		if(inStr[i] == '\0') {
			return;
		}
	}
}

void myStrCpy2(const char *inStr, char * outStr) {
	
	memcpy(outStr, inStr, strlen(inStr) + 1);
}

void myStrCpyOpos(const char *inStr, char * outStr) {
	
	for(int i = 0;;i++) {
		if(inStr[i] == '\0') {
			outStr[i] = inStr[i];
			return;
		}
		
		outStr[strlen(inStr) - i - 1] = inStr[i];
	}
}

void own_itoa(long long int value_to_be_converted, char * output_string) {
	sprintf(output_string, "%lli", value_to_be_converted);
}

void own_itoa2(long long int value_to_be_converted, char * output_string) {
	
	long long int value = value_to_be_converted;
	int val_size = log10(value);
	int ret = 0;
	
	
	char buffer[val_size];
	buffer[0] = '\0';
	char buffer2[val_size];
	buffer2[0] = '\0';
	
	while(1) {
		ret = value % 10;
		value = value / 10;
		
		buffer[0] = ret + '0';
		buffer[1] = '\0';
		
		strcat(buffer, buffer2);
		strcpy(buffer2, buffer);
		
		if(value == 0) {
			strcat(output_string, buffer2);
			return;
		}
	}
}

int main(int argc, const char * argv[]) {
	
	const char * inString = "This is input string";
	const char * inString2 = "0123456789";
	char outString[strlen(inString)];
	char outString2[strlen(inString)];
	char outString3[strlen(inString)];
	outString[0] = '\0';
	outString2[0] = '\0';
	outString3[0] = '\0';
	
	printf("1)input string: %s\n", inString);
	printf("2)output buffer: %s\n", outString);
	
	myStrCpy1(inString, outString);
	
	printf("3)output string: %s\n", outString);
	
	myStrCpy2(inString, outString2);
	printf("4)output string: %s\n", outString2);
	
	myStrCpyOpos(inString2, outString3);
	printf("5)output string reordered: %s\n", outString3);
	
	if(argc <= 1) {
		return 0;
	}
	char outString4[strlen(argv[1])];
	myStrCpyOpos(argv[1], outString4);
	printf("6)output string reordered: %s\n", outString4);
	
	long long int value = 1324657980;
	int val_size = log10(value);
	
	char outString5[val_size];
	outString5[0] = '\0';
	printf("7)input number is: %lli\n", value);
	own_itoa(value, outString5);
	printf("8)output number as a string: %s\n", outString5);
	
	char outString6[val_size];
	outString6[0] = '\0';
	own_itoa2(value, outString6);
	printf("9)output number as a string: %s\n", outString6);

    return 0;
}