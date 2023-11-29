// grade.h
#include "assignment.h"

#ifndef GRADE_H
#define GRADE_H

#define MAX_STUDENT_NAME_LENGTH 50
#define MAX_COURSES_IN_STUDENT 10  // 假设一个学生最多选修10门课程

// 成绩信息结构体
typedef struct {
    char studentName[MAX_STUDENT_NAME_LENGTH];
    char courses[MAX_COURSES_IN_STUDENT][MAX_ASSIGNMENT_NAME_LENGTH];
    int scores[MAX_COURSES_IN_STUDENT];
    int courseCount;
} Grade;

// 成绩管理函数
Grade* createGrade(const char* studentName);
void deleteGrade(Grade* grade);
void printGradeInfo(Grade* grade);
void addCourseGrade(Grade* grade, const char* courseName, int score);

#endif // GRADE_H