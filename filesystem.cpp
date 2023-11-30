#include "filesystem.h"
#include <algorithm>

Course* FileSystem::findCourse(const std::string& courseName, const std::string& teacherName) const {
    for (auto& coursePtr : courses) {
        if (coursePtr->getCourseName() == courseName && coursePtr->getTeacherName() == teacherName) {
            return coursePtr;
        }
    }
    return nullptr;
}

Course* FileSystem::createCourse(const std::string& courseName, const std::string& teacherName) {
    Course* existingCourse = findCourse(courseName, teacherName);
    if (existingCourse) {
        std::cout << "Course already exists." << std::endl;
        return existingCourse;
    } else {
        Course* newCourse = new Course(courseName, teacherName);
        courses.push_back(newCourse);
        std::cout << "Course created." << std::endl;
        return newCourse;
    }
}

void FileSystem::deleteCourse(const std::string& courseName, const std::string& teacherName) {
    auto it = std::remove_if(courses.begin(), courses.end(),
                             [&](const Course* course) {
                                 return course->getCourseName() == courseName && course->getTeacherName() == teacherName;
                             });

    if (it != courses.end()) {
        delete *it; // 删除在堆上分配的 Course 对象
        courses.erase(it, courses.end());
        std::cout << "Course deleted." << std::endl;
    } else {
        std::cout << "Course not found." << std::endl;
    }
}

void FileSystem::addStudentToCourse(const std::string& courseName, const std::string& teacherName, const std::string& studentName) {
    Course* course = findCourse(courseName, teacherName);
    if (course) {
        course->addStudent(studentName);
        std::cout << "Student added to the course." << std::endl;
    } else {
        std::cout << "Course not found." << std::endl;
    }
}

void FileSystem::gradeStudent(const std::string& courseName, const std::string& teacherName, const std::string& studentName, int finalGrade) {
    Course* course = findCourse(courseName, teacherName);
    if (course) {
        course->gradeStudent(studentName, finalGrade);
        std::cout << "Student graded." << std::endl;
    } else {
        std::cout << "Course not found." << std::endl;
    }
}

void FileSystem::printCourseInfo(const std::string& courseName, const std::string& teacherName) const {
    Course* course = findCourse(courseName, teacherName);
    if (course) {
        course->printCourseInfo();
    } else {
        std::cout << "Course not found." << std::endl;
    }
}

Assignment* FileSystem::findAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex) const {
    for (auto& assignmentPtr : assignments) {
        if (assignmentPtr->getCourseName() == courseName &&
            assignmentPtr->getTeacherName() == teacherName &&
            assignmentPtr->getAssignmentIndex() == assignmentIndex) {
            return assignmentPtr;
        }
    }
    return nullptr;
}

Assignment* FileSystem::createAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex) {
    Assignment* existingAssignment = findAssignment(courseName, teacherName, assignmentIndex);
    if (existingAssignment) {
        std::cout << "Assignment already exists." << std::endl;
        return existingAssignment;
    } else {
        Assignment* newAssignment = new Assignment(courseName, teacherName, assignmentIndex);
        assignments.push_back(newAssignment);
        std::cout << "Assignment created." << std::endl;
        return newAssignment;
    }
}

void FileSystem::deleteAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex) {
    auto it = std::remove_if(assignments.begin(), assignments.end(),
                             [&](const Assignment* assignment) {
                                 return assignment->getCourseName() == courseName &&
                                        assignment->getTeacherName() == teacherName &&
                                        assignment->getAssignmentIndex() == assignmentIndex;
                             });

    if (it != assignments.end()) {
        delete *it; // 删除在堆上分配的 Assignment 对象
        assignments.erase(it, assignments.end());
        std::cout << "Assignment deleted." << std::endl;
    } else {
        std::cout << "Assignment not found." << std::endl;
    }
}

void FileSystem::addStudentToAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex, const std::string& studentName) {
    Assignment* assignment = findAssignment(courseName, teacherName, assignmentIndex);
    if (assignment) {
        assignment->addStudent(studentName);
        std::cout << "Student added to the assignment." << std::endl;
    } else {
        std::cout << "Assignment not found." << std::endl;
    }
}

void FileSystem::gradeStudentInAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex, const std::string& studentName, int grade) {
    Assignment* assignment = findAssignment(courseName, teacherName, assignmentIndex);
    if (assignment) {
        assignment->gradeStudent(studentName, grade);
        std::cout << "Student graded in the assignment." << std::endl;
    } else {
        std::cout << "Assignment not found." << std::endl;
    }
}

void FileSystem::printAssignmentInfo(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex) const {
    Assignment* assignment = findAssignment(courseName, teacherName, assignmentIndex);
    if (assignment) {
        assignment->printAssignmentInfo();
    } else {
        std::cout << "Assignment not found." << std::endl;
    }
}
