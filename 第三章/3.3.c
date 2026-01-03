#include <stdio.h>
#include <complex.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {
    int x = 100;
    printf("%lld %o %x %#o %#x\n", __LONG_LONG_MAX__, x, x, x, x);
    int f = 333333;
    printf("%3d %3d\n", f, f);
    //complex x = 1 + 4*I;
    int c[3] = {1};
    printf("%zd\n", sizeof c);
    printf("%d", EOF);
    bool cmp = false;
    if (cmp) puts("1");
    else puts("0");
    return 0;
}