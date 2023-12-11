#pragma once

#include "FileSystem.h"

/*
File Structure:
(root)
|
|---User
|   |-username1
|   |   └-password(role is in this file)
|   |-username2
|   |   └-password
|   ...
|
└---Course
    |-course_name1
    |   |-assignment1
    |   |   |-Description
    |   |   └-Homework
    |   |   |-title1
    |   |   |   |-Score  
    |   |   |   └-Content
    |   |   |-title2
    |   |   |   |-Score
    |   |   |   └-Content
    |   |       ...
    |   |
    |   |-assignment2
    |   |   └-...
    |   ...
    |
    |-course_name2
    |   └-...
    ...

*/
class Database
{
public:
    Database();

    std::string getLoginStatus(std::string username, std::string password);

    std::string PrintCourse();
    std::string ListUser();

    void CreateUser(std::string username, std::string password, std::string role);
    void DeleteUser(std::string username);

    void CreateCourse(std::string courseName);
    void DeleteCourse(std::string courseName);

    void CreateAssignment(std::string courseName, std::string assignment, std::string content);
    std::string getHomworkTitles(std::string courseName, std::string assignment);
    std::string getHomeworkContent(std::string courseName, std::string assignment, std::string title);
    void MarkHomework(std::string courseName, std::string assignment, std::string title, std::string score);

    std::string getAssignmentTitles(std::string courseName); 
    std::string getAssignmentContent(std::string courseName, std::string assignment);
    void SubmitAssignment(std::string courseName, std::string assignment, std::string title, std::string content);
    std::string getScoreInCourse(std::string courseName, std::string assignment, std::string title);

    void Backup();
    void Recovery();

private:
    FileSystem fileSys;
};