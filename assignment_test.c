// assignment_test.c

#include <stdio.h>
#include "assignment.h"

int main() {
    // 创建作业
    Assignment* mathAssignment = createAssignment("Math Assignment 1");
    printAssignmentInfo(mathAssignment);

    // 为学生打分
    assignGrade(mathAssignment, "John Doe", 90);
    assignGrade(mathAssignment, "Jane Smith", 85);
    printAssignmentInfo(mathAssignment);

    // 添加更多的学生和分数
    assignGrade(mathAssignment, "Bob Johnson", 75);
    assignGrade(mathAssignment, "Alice Brown", 88);
    printAssignmentInfo(mathAssignment);

    // 分数范围检查测试：添加分数超过范围的学生
    assignGrade(mathAssignment, "Tom White", 105);
    printAssignmentInfo(mathAssignment);

    // 打印具体学生分数信息
    printf("\nDetailed Scores:\n");
    for (int i = 0; i < mathAssignment->assignmentCount; ++i) {
        printf("Student: %s, Score: %d\n", mathAssignment->students[i], mathAssignment->scores[i]);
    }

    // 删除作业
    deleteAssignment(mathAssignment);

    return 0;
}

// gcc -o assignment_test assignment.c assignment_test.c