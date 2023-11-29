// assignment.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assignment.h"

// 创建作业
Assignment* createAssignment(const char* name) {
    Assignment* assignment = malloc(sizeof(Assignment));
    if (assignment != NULL) {
        strncpy(assignment->name, name, MAX_ASSIGNMENT_NAME_LENGTH - 1);
        assignment->name[MAX_ASSIGNMENT_NAME_LENGTH - 1] = '\0';
        assignment->assignmentCount = 0;
    }
    return assignment;
}

// 删除作业
void deleteAssignment(Assignment* assignment) {
    if (assignment != NULL) {
        free(assignment);
    }
}

// 打印作业信息
void printAssignmentInfo(Assignment* assignment) {
    if (assignment != NULL) {
        printf("Assignment Name: %s\n", assignment->name);
        printf("Number of students submitted: %d\n", assignment->assignmentCount);
        // 打印其他作业信息
    }
}

// 为学生打分
void assignGrade(Assignment* assignment, const char* studentName, int score) {
    if (assignment != NULL && assignment->assignmentCount < MAX_ASSIGNMENTS_IN_COURSE) {
        strncpy(assignment->students[assignment->assignmentCount], studentName, MAX_STUDENT_NAME_LENGTH - 1);
        assignment->students[assignment->assignmentCount][MAX_STUDENT_NAME_LENGTH - 1] = '\0';
        assignment->scores[assignment->assignmentCount] = score;
        assignment->assignmentCount++;
    }
}
