#include <stdio.h>

int printInputArgs(int argc, char * argv[]);

int main(int argc, char * const argv[]) {
    
	//program args
	printInputArgs(argc, argv);
	
	//Not allowed to overwrite * const
	//argv[0] = "printInputArgs";
	
	printInputArgs(argc, argv);
    
    return 0;
}


int printInputArgs(int argc, char * argv[])
{	
	for(int i = 0; i < argc; i++) {
		printf("%d: %s\n", i, argv[i]);
	}
	
	//Allowed to overwrite * where const was intentionaly removed
	argv[0] = "printInputArgs";
	
	printf("\n");
	
	return argc;
}