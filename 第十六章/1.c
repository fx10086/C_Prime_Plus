#include <stdio.h>
#line 10 "2.c"
#define PR(x, ...) printf("I am " #x __VA_ARGS__)

int main() {
    double a = 42;

    printf(__TIME__);
    return 0;
}