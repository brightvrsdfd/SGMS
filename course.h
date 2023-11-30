#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>

class Course {
public:
    Course(const std::string& courseName, const std::string& teacherName);

    std::string getCourseName() const;
    std::string getTeacherName() const;

    void addStudent(const std::string& studentName);
    void gradeStudent(const std::string& studentName, int finalGrade);

    void printCourseInfo() const;

private:
    std::string courseName;
    std::string teacherName;
    std::vector<std::string> studentNames;
    std::vector<int> finalGrades;
};

#endif // COURSE_H