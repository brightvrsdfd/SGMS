// course_test.c

#include <stdio.h>
#include "course.h"

int main() {
    // 创建课程
    Course* mathCourse = createCourse("Math", "Mr. Smith");
    printCourseInfo(mathCourse);

    // 添加学生到课程
    addStudentToCourse(mathCourse, "John Doe");
    addStudentToCourse(mathCourse, "Jane Smith");
    printCourseStudents(mathCourse);

    // 添加更多的学生
    addStudentToCourse(mathCourse, "Bob Johnson");
    addStudentToCourse(mathCourse, "Alice Brown");
    printCourseStudents(mathCourse);

    // 学生数量检查测试：添加超过限制的学生
    addStudentToCourse(mathCourse, "Tom White");
    printCourseStudents(mathCourse);

    // 删除课程
    deleteCourse(mathCourse);

    return 0;
}

// gcc -o course_test course.c course_test.c