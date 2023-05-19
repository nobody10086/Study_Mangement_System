#include "functions.h"
#include "grade.h"

void displayCard() {
    char sno[4];
    int found = 0;

    printf("Enter student number to search: ");
    scanf("%s", sno);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].sno, sno) == 0) {
            printf("Student number: %s\n", students[i].sno);
            printf("Name: %s\n", students[i].name);
            printf("Chinese grade: %.2f\n", students[i].chinese_grade);
            printf("Math grade: %.2f\n", students[i].math_grade);
            printf("English grade: %.2f\n", students[i].english_grade);
            printf("C language grade: %.2f\n", students[i].c_grade);
            printf("Total grade: %.2f\n", students[i].total_grade);
            printf("Average grade: %.2f\n", students[i].average_grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found\n");
    }
}
