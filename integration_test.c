// integrated_test.c

#include <stdio.h>
#include "user.h"
#include "filesystem.h"
#include "course.h"
#include "grade.h"
#include "assignment.h"

int main() {
    // Create users
    User* admin = createUser("admin", "adminpass", ADMIN);
    User* teacher = createUser("teacher", "teacherpass", TEACHER);
    User* student1 = createUser("student1", "studentpass", STUDENT);
    User* student2 = createUser("student2", "studentpass", STUDENT);

    // Initialize file system
    FileSystem fs;
    initFileSystem(&fs);

    // Create courses
    Course* mathCourse = createCourse("Math", teacher->username);
    Course* historyCourse = createCourse("History", teacher->username);

    // Enroll students in courses
    addStudentToCourse(mathCourse, student1->username);
    addStudentToCourse(historyCourse, student1->username);
    addStudentToCourse(historyCourse, student2->username);

    // Create assignments
    Assignment* mathAssignment = createAssignment("Math Assignment 1");
    Assignment* historyAssignment = createAssignment("History Assignment 1");

    // Grade students
    Grade* mathGradeStudent1 = createGrade(student1->username);
    Grade* historyGradeStudent1 = createGrade(student1->username);
    Grade* historyGradeStudent2 = createGrade(student2->username);

    // Assign grades
    addCourseGrade(mathGradeStudent1, mathAssignment->name, 90);
    addCourseGrade(historyGradeStudent1, historyAssignment->name, 85);
    addCourseGrade(historyGradeStudent2, historyAssignment->name, 88);

    // Display user information
    printUserInfo(admin);
    printUserInfo(teacher);
    printUserInfo(student1);
    printUserInfo(student2);

    // Display course information
    printCourseInfo(mathCourse);
    printCourseInfo(historyCourse);

    // Display assignment information
    printAssignmentInfo(mathAssignment);
    printAssignmentInfo(historyAssignment);

    // Display grades
    printGradeInfo(mathGradeStudent1);
    printGradeInfo(historyGradeStudent1);
    printGradeInfo(historyGradeStudent2);

    // Clean up
    deleteGrade(mathGradeStudent1);
    deleteGrade(historyGradeStudent1);
    deleteGrade(historyGradeStudent2);

    deleteAssignment(mathAssignment);
    deleteAssignment(historyAssignment);

    deleteCourse(mathCourse);
    deleteCourse(historyCourse);

    // Release memory
    deleteUser(admin);
    deleteUser(teacher);
    deleteUser(student1);
    deleteUser(student2);

    return 0;
}

// gcc -o integration_test integration_test.c user.c filesystem.c course.c grade.c assignment.c
