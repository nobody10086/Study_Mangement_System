#ifndef GRADE_H
#define GRADE_H

struct grade {
    char sno[4];        /* 学号 */
    char name[20];    /* 姓名 */
    float chinese_grade;    /* 语文成绩 */
    float math_grade;    /* 数学成绩 */
    float english_grade;    /* 英语成绩 */
    float c_grade;        /* C 语言成绩 */
    float total_grade;        /* 总分数 */
    float average_grade;        /* 均分数 */
};

#endif
