
#include <stdio.h>

int main(int argc, char *argv[]) {
    int count;

    printf("The command line has %d arguments:\n", argc - 1);
    for (count = 0; count < argc; count++) {
        printf("Argument %d: %s\n", count, argv[count]);
    }
    return 0;
}