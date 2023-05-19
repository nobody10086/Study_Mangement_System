#include "functions.h"
#include "grade.h"

void sortCard() {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - 1 - i; j++) {
            if (students[j].average_grade < students[j + 1].average_grade) {
                struct grade temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < numStudents; i++) {
        printf("%d. %s, %.2f\n", i + 1, students[i].name, students[i].average_grade);
    }
}
