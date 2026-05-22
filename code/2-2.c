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

    // fscanf, feof 사용해 파일 끝까지 읽어 적절한 형태로 변환
    while (!feof(fp)) {
        fscanf(fp, "%s %d", students[count].name, &students[count].score);
        count++;
    }

    int max = 0;
    float avg = 0;

    for (int i = 0; i < count - 1; i++) {
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

