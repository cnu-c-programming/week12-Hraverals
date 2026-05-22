#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");

    int counter[26] = {0}; 
    int c;                 

    while ((c = fgetc(fp)) != EOF) {
        int idx = c - 'a';
        if (0 <= idx && idx < 26) {
            counter[idx]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, counter[i]);
    }

    fclose(fp);
}

