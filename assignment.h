// assignment.h

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#define MAX_ASSIGNMENT_NAME_LENGTH 100
#define MAX_STUDENT_NAME_LENGTH 50
#define MAX_ASSIGNMENTS_IN_COURSE 10  // 假设一个课程最多有10个作业

// 作业信息结构体
typedef struct {
    char name[MAX_ASSIGNMENT_NAME_LENGTH];
    char students[MAX_ASSIGNMENTS_IN_COURSE][MAX_STUDENT_NAME_LENGTH];
    int scores[MAX_ASSIGNMENTS_IN_COURSE];
    int assignmentCount;
} Assignment;

// 作业管理函数
Assignment* createAssignment(const char* name);
void deleteAssignment(Assignment* assignment);
void printAssignmentInfo(Assignment* assignment);
void assignGrade(Assignment* assignment, const char* studentName, int score);

#endif // ASSIGNMENT_H
