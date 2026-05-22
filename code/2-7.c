#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");
    //파일을 구조체에 저장

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, "=");
        if (token == NULL) continue;

        if (strcmp(token, "InputFileName") == 0) {
            token = strtok(NULL, "\n");
            if (token) {
                strncpy(config_ptr->InputFileName, token, sizeof(config_ptr->InputFileName) - 1);
                config_ptr->InputFileName[sizeof(config_ptr->InputFileName) - 1] = '\0';
            }
        } else if (strcmp(token, "Options") == 0) {
            token = strtok(NULL, "\n");
            if (token) {
                config_ptr->Options = atoi(token);
            }
        } else if (strcmp(token, "SectionName") == 0) {
            token = strtok(NULL, "\n");
            if (token) {
                strncpy(config_ptr->SectionName, token, sizeof(config_ptr->SectionName) - 1);
                config_ptr->SectionName[sizeof(config_ptr->SectionName) - 1] = '\0';
            }
        } else if (strcmp(token, "Address") == 0) {
            token = strtok(NULL, "\n");
            if (token) {
                config_ptr->Address = strtoull(token, NULL, 16);
            }
        }
    }

    fclose(fp);
}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}

