#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    FILE *out = fopen("2.c", "wb");
    if (out == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0L, SEEK_END);
    int last = ftell(file), byte;
    fseek(file, 0L, SEEK_SET);
    char ch[last];
    byte = fread(ch, sizeof(char), last, file);
    printf("%d\n", last);
    fwrite(ch, sizeof(char), byte, out);
    // for (int i = 0L; i < last; i++) {
    //     fseek(file, i, SEEK_SET);
    //     char ch = fgetc(file);
    //     putc(ch, out);
    // }
    exit(EXIT_SUCCESS);
}