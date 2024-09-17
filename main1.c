#include <stdio.h>

int main(int argc, char *argv[]) {
    
    //conditional instructions
    int a = 3;
    int b = 4;
    
    if(a > b) {
      printf("a > b\n");  
    } else if(b > a) {
       printf("b > a\n"); 
    } else {
        printf("a = b\n"); 
    }
    
    a > b ? printf("a>b") : b > a ? printf("b>a") : printf("a=b");
    printf("\n\n"); 
    
    switch (a) {
        case 1: printf("1\n");
            break;
        case 2: printf("2\n");
            break;
        case 3: printf("3\n");
            break;
        default: printf("other value\n");
            break;
    }
    printf("\n\n");
    
    
    //loops
    for(int i = 0; i <= 5; i++) {
        printf("%d", i);
    }
    printf("\n");
    
    int i = 0;
    while(i <= 5) printf("%d", i++);
    
    do {printf("%d", i++);}
    while(i <= 10);
    printf("\n\n");
    
    
    //bit shifting
    int c = 0x0F;
    printf("%x\n",c);
    int d = c << 4;
    printf("%x\n",d);
    int e = c >> 2;
    printf("%x\n",e);
    printf("\n\n");
    
    
    //sizeof
    char f = 255;
    short int g = 1000;
    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(f));
    printf("%d\n", sizeof(g));
    
    
    //goto
    printf("before goto\n");
    goto jump;
    printf("after goto\n");
jump:    
    printf("label\n");
    
    return 0;
}