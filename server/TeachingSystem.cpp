#include "TeachingSystem.h"
#include <vector>
#include <iostream>

using namespace std;

string TeachingSystem::getInfo(string path)
{
    return fileSys->getList(path);
}

TeachingSystem::TeachingSystem()
{
    fileSys = new FileSystem;
    fileSys->CreateDir("User");
    fileSys->CreateDir("User/ADMIN");
    fileSys->CreateDir("User/TEACHER");
    fileSys->CreateDir("User/STUDENT");
    fileSys->CreateDir("Course");
}

string TeachingSystem::getLoginStatus(string username, string password)
{
    string role = fileSys->getFileCont("User/ADMIN/" + username + "/" + password);
    role += fileSys->getFileCont("User/TEACHER/" + username + "/" + password);
    role += fileSys->getFileCont("User/STUDENT/" + username + "/" + password);

    if (role.empty())
        return "ERROR";

    return role;
}

string TeachingSystem::ListUser(){
    std::vector<std::string> list_admin = fileSys->getListVector("User/ADMIN");
    std::vector<std::string> list_teacher = fileSys->getListVector("User/TEACHER");
    std::vector<std::string> list_student = fileSys->getListVector("User/STUDENT");

    if (list_admin.empty() && list_teacher.empty() && list_student.empty()) {
        return "There is no user in the system.\n";
    }

    std::string res = "There are these users in this system:\n";

    res += "  Admin:\n";
    for (const auto& user : list_admin) {
        res += "    " + user + "\n";
    }

    res += "  Teacher:\n";
    for (const auto& user : list_teacher) {
        res += "    " + user + "\n";
    }

    res += "  Student:\n";
    for (const auto& user : list_student) {
        res += "    " + user + "\n";
    }

    return res;
}

string TeachingSystem::ShowAllInfo(){
    string path = "/";
    string AllInfo = fileSys->getListTree(path);
    cout << AllInfo << endl;
    cout << fileSys << endl;
    return AllInfo;
}

void TeachingSystem::CreateUser(string username, string password, string role)
{
    if (role=="1")
    {
        string path = "User/ADMIN/" + username;
        fileSys->CreateDir(path);

        path = path + "/" + password;
        fileSys->CreateFile(path);

        fileSys->WriteFile(path, role);
    }
    if (role=="2")
    {
        string path = "User/TEACHER/" + username;
        fileSys->CreateDir(path);

        path = path + "/" + password;
        fileSys->CreateFile(path);

        fileSys->WriteFile(path, role);
    }
    if (role=="3")
    {
        string path = "User/STUDENT/" + username;
        fileSys->CreateDir(path);

        path = path + "/" + password;
        fileSys->CreateFile(path);

        fileSys->WriteFile(path, role);
    }
}

void TeachingSystem::DeleteUser(string username)
{
    string path = "User/ADMIN/" + username;
    fileSys->Delete(path);
    path = "User/TEACHER/" + username;
    fileSys->Delete(path);
    path = "User/STUDENT/" + username;
    fileSys->Delete(path);
}

void TeachingSystem::CreateCourse(std::string teacherName, std::string courseName)
{
    string path = "Course/" + teacherName;
    fileSys->CreateDir(path);
    path = "Course/" + teacherName + "/" + courseName;
    fileSys->CreateDir(path);
}

void TeachingSystem::DeleteCourse(std::string teacherName, std::string courseName)
{
    string path = "Course/" + teacherName + "/" + courseName;
    fileSys->Delete(path);
}

void TeachingSystem::CreateAssignment(std::string teacherName, std::string courseName, std::string assignment, std::string content)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment;
    fileSys->CreateDir(path);
    fileSys->CreateFile(path + "/Description");
    fileSys->WriteFile(path + "/Description", content);
}

void TeachingSystem::DeleteAssignment(std::string teacherName, std::string courseName, std::string assignment)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment;
    fileSys->Delete(path);
}

void TeachingSystem::SubmitAssignment(std::string teacherName, std::string studentName, std::string courseName, std::string assignment, std::string content)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName;
    fileSys->CreateDir(path);
    fileSys->CreateFile(path + "/submission");
    fileSys->CreateFile(path + "/mark");
    fileSys->WriteFile(path + "/submission", content);
}

void TeachingSystem::DeleteSubmission(std::string teacherName, std::string studentName, std::string courseName, std::string assignment)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName;
    fileSys->Delete(path);
}

void TeachingSystem::MarkSubmission(std::string teacherName, std::string studentName, std::string courseName, std::string assignment, std::string mark)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName + "/mark";
    fileSys->Delete(path);
    fileSys->CreateFile(path);
    fileSys->WriteFile(path, mark);
}

std::string TeachingSystem::getCourseInfo(std::string teacherName, std::string courseName)
{
    std::string path = "Course/" + teacherName + "/" + courseName;
    std::string courseList = fileSys->getListTree(path);
    return courseList;
}

std::string TeachingSystem::getAssignmentInfo(std::string teacherName, std::string courseName, std::string assignment)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/Description";
    std::string assignmentInfo = fileSys->getFileCont(path);
    return assignmentInfo;
}

std::string TeachingSystem::getSubmissionInfo(std::string teacherName, std::string courseName, std::string assignment, std::string studentName)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName + "/submission";
    std::string subInfo = fileSys->getFileCont(path);
    return subInfo;
}

std::string TeachingSystem::getSubmissionMark(std::string teacherName, std::string courseName, std::string assignment, std::string studentName)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName + "/mark";
    std::string mark = fileSys->getFileCont(path);
    return mark;
}

void TeachingSystem::Backup()
{
    // lock_guard<mutex> lock(courseMutex);
    fileSys->Delete("Backup");
    fileSys->CreateDir("Backup");
    fileSys->Copy("User", "Backup");
    fileSys->Copy("Course", "Backup");
}

void TeachingSystem::Recovery()
{
    // lock_guard<mutex> lock(courseMutex);
    fileSys->Delete("User");
    fileSys->Delete("Course");
    fileSys->Copy("Backup/User", "");
    fileSys->Copy("Backup/Course", "");
}