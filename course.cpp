#include "course.h"
#include <algorithm>

Course::Course(const std::string& courseName, const std::string& teacherName)
    : courseName(courseName), teacherName(teacherName) {}

std::string Course::getCourseName() const {
    return courseName;
}

std::string Course::getTeacherName() const {
    return teacherName;
}

void Course::addStudent(const std::string& studentName) {
    if (std::find(studentNames.begin(), studentNames.end(), studentName) == studentNames.end()) {
        studentNames.push_back(studentName);
        finalGrades.push_back(0); // 初始分数为0
    }
}

void Course::gradeStudent(const std::string& studentName, int finalGrade) {
    auto it = std::find(studentNames.begin(), studentNames.end(), studentName);
    if (it != studentNames.end()) {
        size_t index = std::distance(studentNames.begin(), it);
        finalGrades[index] = finalGrade;
    } else {
        studentNames.push_back(studentName);
        finalGrades.push_back(finalGrade);
    }
}

void Course::printCourseInfo() const {
    std::cout << "Course Name: " << courseName << std::endl;
    std::cout << "Teacher Name: " << teacherName << std::endl;

    std::cout << "Students and Grades:" << std::endl;
    for (size_t i = 0; i < studentNames.size(); ++i) {
        std::cout << "  " << studentNames[i] << ": ";
        if (finalGrades[i] == 0) {
            std::cout << "-" << std::endl;
        } else {
            std::cout << finalGrades[i] << std::endl;
        }
    }
    std::cout << std::endl;
}