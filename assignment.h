#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>
#include <vector>

class Assignment {
public:
    Assignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex);

    std::string getCourseName() const;
    std::string getTeacherName() const;
    std::string getAssignmentIndex() const;

    void addStudent(const std::string& studentName);
    void gradeStudent(const std::string& studentName, int grade);

    void printAssignmentInfo() const;

private:
    std::string courseName;
    std::string teacherName;
    std::string assignmentIndex;
    std::vector<std::string> studentNames;
    std::vector<int> grades;
};

#endif // ASSIGNMENT_H
