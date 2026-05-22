#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;
    
    const char* filename = argv[1];
    char buffer[10] = {0};

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("error: cannot open");
        return 1;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s\n", buffer);
    }

    fclose(fp);
    return 0;
}