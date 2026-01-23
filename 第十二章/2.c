#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    int a, cnt = 0, sum = 0;
    while (scanf("%d", &a) == 1) ++cnt;
    while (getchar() != '\n') ++sum;
    printf("cnt = %d, sum = %d\n", cnt, sum);
    return 0;
}