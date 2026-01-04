#include <stdio.h>
#include "fx10086.h"

int main(void) {
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != EOF)
        ++cnt;
    printf("Total characters: %d\n", function(cnt));
    return 0; 
}