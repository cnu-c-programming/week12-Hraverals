#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    const char* target_str = argv[2];
    
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, target_str)) {
            printf("%s", line);
        }
    }

    fclose(fp);
}

