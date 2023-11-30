#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "course.h"
#include "assignment.h"
#include <vector>

class FileSystem {
public:
    // 通过 courseName 和 teacherName 查询课程，如果不存在则返回 nullptr
    Course* findCourse(const std::string& courseName, const std::string& teacherName) const;

    // 创建课程，如果已存在则返回已创建的信息
    Course* createCourse(const std::string& courseName, const std::string& teacherName);

    // 删除课程，如果不存在则返回课程不存在的信息
    void deleteCourse(const std::string& courseName, const std::string& teacherName);

    // 添加学生到课程
    void addStudentToCourse(const std::string& courseName, const std::string& teacherName, const std::string& studentName);

    // 为学生打分
    void gradeStudent(const std::string& courseName, const std::string& teacherName, const std::string& studentName, int finalGrade);

    // 打印课程信息
    void printCourseInfo(const std::string& courseName, const std::string& teacherName) const;

    // 通过 courseName、teacherName 和 assignmentIndex 查询作业，如果不存在则返回 nullptr
    Assignment* findAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex) const;

    // 创建作业
    Assignment* createAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex);

    // 删除作业
    void deleteAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex);

    // 添加学生到作业
    void addStudentToAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex, const std::string& studentName);

    // 为学生打分（作业）
    void gradeStudentInAssignment(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex, const std::string& studentName, int grade);

    // 打印作业信息
    void printAssignmentInfo(const std::string& courseName, const std::string& teacherName, const std::string& assignmentIndex) const;

private:
    std::vector<Course*> courses; // 存储指向 Course 对象的指针
    std::vector<Assignment*> assignments; // 存储指向 Assignment 对象的指针
};

#endif // FILESYSTEM_H
