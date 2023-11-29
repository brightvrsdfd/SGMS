// grade.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade.h"

// 创建成绩
Grade* createGrade(const char* studentName) {
    Grade* grade = malloc(sizeof(Grade));
    if (grade != NULL) {
        strncpy(grade->studentName, studentName, MAX_STUDENT_NAME_LENGTH - 1);
        grade->studentName[MAX_STUDENT_NAME_LENGTH - 1] = '\0';
        grade->courseCount = 0;
    }
    return grade;
}

// 删除成绩
void deleteGrade(Grade* grade) {
    if (grade != NULL) {
        free(grade);
    }
}

// 打印成绩信息
void printGradeInfo(Grade* grade) {
    if (grade != NULL) {
        printf("Student Name: %s\n", grade->studentName);
        printf("Number of courses taken: %d\n", grade->courseCount);
        // 打印其他成绩信息
    }
}

// 添加课程成绩
void addCourseGrade(Grade* grade, const char* courseName, int score) {
    if (grade != NULL && grade->courseCount < MAX_COURSES_IN_STUDENT) {
        strncpy(grade->courses[grade->courseCount], courseName, MAX_ASSIGNMENT_NAME_LENGTH - 1);
        grade->courses[grade->courseCount][MAX_ASSIGNMENT_NAME_LENGTH - 1] = '\0';
        grade->scores[grade->courseCount] = score;
        grade->courseCount++;
    }
}
