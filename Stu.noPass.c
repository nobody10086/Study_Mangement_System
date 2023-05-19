#include "functions.h"
#include "grade.h"

void noPass() {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].average_grade < 60) {
            printf("Student number: %s\n", students[i].sno);
            printf("Name: %s\n", students[i].name);
            printf("Average grade: %.2f\n", students[i].average_grade);
        }
    }
}
