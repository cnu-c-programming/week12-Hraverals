#include <stdio.h>

int main(int argc, const char* argv[], const char* envp[]) {
    *envp = envp[0]; 

    while (*envp != NULL) {
        printf("%s\n", *envp);
        envp++;
    }

    return 0;
}