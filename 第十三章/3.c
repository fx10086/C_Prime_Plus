#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[10] = "1", b[] = "1234";
    strcpy(a, b);
    printf("%s\n", a);
}