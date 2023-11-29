// course.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"

// 创建课程
Course* createCourse(const char* name, const char* teacher) {
    Course* course = malloc(sizeof(Course));
    if (course != NULL) {
        strncpy(course->name, name, MAX_COURSE_NAME_LENGTH - 1);
        course->name[MAX_COURSE_NAME_LENGTH - 1] = '\0';
        strncpy(course->teacher, teacher, MAX_TEACHER_NAME_LENGTH - 1);
        course->teacher[MAX_TEACHER_NAME_LENGTH - 1] = '\0';
        // 初始化其他课程信息
    }
    return course;
}

// 删除课程
void deleteCourse(Course* course) {
    if (course != NULL) {
        free(course);
    }
}

// 打印课程信息
void printCourseInfo(Course* course) {
    if (course != NULL) {
        printf("Course Name: %s\n", course->name);
        printf("Teacher: %s\n", course->teacher);
        // 打印其他课程信息
    }
}

// 打印课程学生列表
void printCourseStudents(Course* course) {
    if (course != NULL) {
        printf("Students in course %s:\n", course->name);
        if (course->studentCount > 0) {
            for (int i = 0; i < course->studentCount; ++i) {
                printf("%s\n", course->students[i]);
            }
        } else {
            printf("No students enrolled.\n");
        }
    }
}

// 添加学生到课程
void addStudentToCourse(Course* course, const char* studentName) {
    if (course != NULL && course->studentCount < MAX_STUDENTS_IN_COURSE) {
        strncpy(course->students[course->studentCount], studentName, MAX_STUDENT_NAME_LENGTH - 1);
        course->students[course->studentCount][MAX_STUDENT_NAME_LENGTH - 1] = '\0';
        course->studentCount++;
    }
}