// course.h

#ifndef COURSE_H
#define COURSE_H

#define MAX_COURSE_NAME_LENGTH 100
#define MAX_TEACHER_NAME_LENGTH 50
#define MAX_STUDENT_NAME_LENGTH 50
#define MAX_STUDENTS_IN_COURSE 10  // 假设一个课程最多有10个学生

// 课程信息结构体
typedef struct {
    char name[MAX_COURSE_NAME_LENGTH];
    char teacher[MAX_TEACHER_NAME_LENGTH];
    char students[MAX_STUDENTS_IN_COURSE][MAX_STUDENT_NAME_LENGTH];
    int studentCount;
} Course;

// 课程管理函数
Course* createCourse(const char* name, const char* teacher);
void deleteCourse(Course* course);
void printCourseInfo(Course* course);

// 学生管理函数
void addStudentToCourse(Course* course, const char* studentName);
void printCourseStudents(Course* course);

#endif // COURSE_H
