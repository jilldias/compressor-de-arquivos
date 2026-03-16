#include <stdio.h>
#include <string.h>

void compress(FILE *in, FILE *out){
    int prev = fgetc(in);
    int ch, count;

    while (prev != EOF){
        count = 1;
        while ((ch = fgetc(in)) == prev && count < 255) {
            count++;
        }
        putc(count, out);
        putc(prev, out);
        prev = ch;
        }
    }

    void decompress(FILE *in, FILE *out){
        int count, ch;

        while ((count = fgetc(in))!= EOF){
            ch = fgetc(in);
            for(int i = 0; i < count; i++)
                fputc(ch, out);
        }
    }
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s -c|-d input output\n", argv[0]);
        return 1;
    }

    FILE *in  = fopen(argv[2], "rb");
    FILE *out = fopen(argv[3], "wb");

    if (!in || !out) {
        printf("Error: could not open files.\n");
        return 1;
    }

    if      (strcmp(argv[1], "-c") == 0) compress(in, out);
    else if (strcmp(argv[1], "-d") == 0) decompress(in, out);
    else    printf("Unknown flag. Use -c to compress or -d to decompress.\n");

    fclose(in);
    fclose(out);
    return 0;
}