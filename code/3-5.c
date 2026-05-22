#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char line[256];
    int sum = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        int val;
        if (sscanf(line, "%d", &val) == 1) {
            sum += val;
        } else {
            fprintf(stderr, "invalid input %s", line);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
