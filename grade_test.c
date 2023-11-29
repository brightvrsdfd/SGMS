// grade_test.c

#include <stdio.h>
#include "grade.h"

int main() {
    // 创建成绩
    Grade* johnGrade = createGrade("John Doe");
    printGradeInfo(johnGrade);

    // 添加课程成绩
    addCourseGrade(johnGrade, "Math", 90);
    addCourseGrade(johnGrade, "History", 85);
    printGradeInfo(johnGrade);

    // 删除成绩
    deleteGrade(johnGrade);

    return 0;
}
