#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]) {
    FILE* fp = fopen("student.txt", "r");
    int count = 0;
    Student students[64];

    while (count < 64 && fscanf(fp, "%63s %d", students[count].name, &students[count].score) == 2) {
        count++;
    }

    if (count == 0) {
        printf("No data found.\n");
        fclose(fp);
        return 0;
    }

    int max = 0;
    float avg = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].score > max) {
            max = students[i].score;
        }
        avg += students[i].score;
    }
    avg /= count;

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);
    return 0;
}