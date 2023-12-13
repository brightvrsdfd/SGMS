#pragma once
#include "FileSystem.h"

class TeachingSystem
{
public:
    TeachingSystem();

    std::string getLoginStatus(std::string username, std::string password);

    std::string ListUser();
    std::string ShowAllInfo();

    void CreateUser(std::string username, std::string password, std::string role);
    void DeleteUser(std::string username);

    void CreateCourse(std::string teacherName, std::string courseName);
    void DeleteCourse(std::string teacherName, std::string courseName);

    void CreateAssignment(std::string teacherName, std::string courseName, std::string assignment, std::string content);
    void DeleteAssignment(std::string teacherName, std::string courseName, std::string assignment, std::string content);

    void SubmitAssignment(std::string teacherName, std::string studentName, std::string courseName, std::string assignment, std::string content);
    void DeleteSubmission(std::string teacherName, std::string studentName, std::string courseName, std::string assignment, std::string content);
    void MarkSubmission(std::string teacherName, std::string studentName, std::string courseName, std::string assignment, std::string mark);

    std::string getCourseInfo(std::string teacherName, std::string courseName);
    std::string getAssignmentInfo(std::string teacherName, std::string courseName, std::string assignment);
    std::string getSubmissionInfo(std::string teacherName, std::string courseName, std::string assignment, std::string studentName);

    std::string getInfo(std::string path);

    void Backup();
    void Recovery();

private:
    FileSystem fileSys;
};