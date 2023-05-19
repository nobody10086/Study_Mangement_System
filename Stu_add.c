#include "functions.h"
#include "grade.h"

void addCard() {
    students = realloc(students, (numStudents + 1) * sizeof(struct grade));

    printf("Enter student number: ");
    scanf("%s", students[numStudents].sno);
    printf("Enter name: ");
    scanf("%s", students[numStudents].name);
    printf("Enter Chinese grade: ");
    scanf("%f", &students[numStudents].chinese_grade);
    printf("Enter Math grade: ");
    scanf("%f", &students[numStudents].math_grade);
    printf("Enter English grade: ");
    scanf("%f", &students[numStudents].english_grade);
    printf("Enter C language grade: ");
    scanf("%f", &students[numStudents].c_grade);

    students[numStudents].total_grade = students[numStudents].chinese_grade + students[numStudents].math_grade + students[numStudents].english_grade + students[numStudents].c_grade;
    students[numStudents].average_grade = students[numStudents].total_grade / 4;

    FILE *file = fopen("students.txt", "a");  // 打开文件，以追加模式
    if (file != NULL) {
        fprintf(file, "%s %s %.2f %.2f %.2f %.2f\n",
                students[numStudents].sno,
                students[numStudents].name,
                students[numStudents].chinese_grade,
                students[numStudents].math_grade,
                students[numStudents].english_grade,
                students[numStudents].c_grade);  // 写入学生信息
        fclose(file);  // 关闭文件
    } else {
        printf("Failed to open the file.\n");
    }

    numStudents++;
}

void loadStudents() {
    FILE *file = fopen("students.txt", "r");  // 打开文件，以只读模式

    if (file != NULL) {
        while (!feof(file)) {
            struct grade student;
            if (fscanf(file, "%s %s %f %f %f %f\n",
                       student.sno,
                       student.name,
                       &student.chinese_grade,
                       &student.math_grade,
                       &student.english_grade,
                       &student.c_grade) == 6) {  // 读取学生信息

                // 在这里处理学生数据，例如添加到你的数组中
                students = realloc(students, (numStudents + 1) * sizeof(struct grade));
                students[numStudents] = student;
                numStudents++;
            }
        }
        fclose(file);  // 关闭文件
    } else {
        printf("Failed to open the file.\n");
    }
}
