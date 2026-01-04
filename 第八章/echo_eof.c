#include <stdio.h>

int main(void) {
    char ch;

    while ((ch = getchar()) != EOF)
        putchar(ch);
    // int a;
    // if(scanf("%d", &a) != 1) {
    //     char ch = getchar();
    //     putchar(ch); 
    //     printf("ERR\n");
    // }
    return 0;
}