#include "functions.h"
#include "grade.h"

void delCard() {
    char sno[4];
    int found = 0;

    printf("Enter student number to delete: ");
    scanf("%s", sno);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].sno, sno) == 0) {
            found = 1;

            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }

            students = realloc(students, (--numStudents) * sizeof(struct grade));
            break;
        }
    }

    if (!found) {
        printf("Student number error!\n");
    }
}
