#include "assignment.h"
#include <algorithm>

Assignment::Assignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex)
    : courseName(courseName), teacherName(teacherName), assignmentIndex(assignmentIndex) {}

std::string Assignment::getCourseName() const {
    return courseName;
}

std::string Assignment::getTeacherName() const {
    return teacherName;
}

std::string Assignment::getAssignmentIndex() const {
    return assignmentIndex;
}

void Assignment::addStudent(const std::string& studentName) {
    if (std::find(studentNames.begin(), studentNames.end(), studentName) == studentNames.end()) {
        studentNames.push_back(studentName);
        grades.push_back(0); // 初始分数为0
    }
}

void Assignment::gradeStudent(const std::string& studentName, int grade) {
    auto it = std::find(studentNames.begin(), studentNames.end(), studentName);
    if (it != studentNames.end()) {
        size_t index = std::distance(studentNames.begin(), it);
        if (index < grades.size()) {
            grades[index] = grade;
        } else {
            // 处理索引越界的情况，可能需要更复杂的逻辑，这里简化处理
            std::cerr << "Error: Index out of range." << std::endl;
        }
    } else {
        studentNames.push_back(studentName);
        grades.push_back(grade);
    }
}

void Assignment::printAssignmentInfo() const {
    std::cout << "Assignment Info:" << std::endl;
    std::cout << "Course Name: " << courseName << std::endl;
    std::cout << "Teacher Name: " << teacherName << std::endl;
    std::cout << "Assignment Index: " << assignmentIndex << std::endl;

    std::cout << "Students and Grades:" << std::endl;
    for (size_t i = 0; i < studentNames.size(); ++i) {
        std::cout << "  " << studentNames[i] << ": ";
        if (grades[i] == 0) {
            std::cout << "-" << std::endl;
        } else {
            std::cout << grades[i] << std::endl;
        }
    }
    std::cout << std::endl;
}
