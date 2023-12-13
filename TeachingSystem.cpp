#include "TeachingSystem.h"
#include <vector>

using namespace std;

string TeachingSystem::getInfo(string path)
{
    return fileSys.getList(path);
}

TeachingSystem::TeachingSystem()
{
    fileSys.CreateDir("User");
    fileSys.CreateDir("Course");
}

string TeachingSystem::getLoginStatus(string username, string password)
{
    string role = fileSys.getFileCont("User/" + username + "/" + password);

    if (role == "")
        return "ERROR";

    return role;
}

string TeachingSystem::ListUser()
{
    vector<string> list = fileSys.getListVector("User");
    if (list.size() == 0)
    {
        return "There is no user in the system.\n";
    }

    string res = "There are these users in this system:\n";
    for (int i = 0; i < list.size(); i++)
    {
        res = res + "    " + list[i] + "\n";
    }
    return res;
}

string TeachingSystem::ShowAllInfo(){
    string path = "/";
    string AllInfo = fileSys.getListTree(path);
    return AllInfo;
}

void TeachingSystem::CreateUser(string username, string password, string role)
{
    string path = "User/" + username;
    fileSys.CreateDir(path);

    path = path + "/" + password;
    fileSys.CreateFile(path);

    fileSys.WriteFile(path, role);

    // fileSys.WriteFile(path, string(1, char(role)));
}

void TeachingSystem::DeleteUser(string username)
{
    string path = "User/" + username;
    fileSys.Delete(path);
}

void TeachingSystem::CreateCourse(std::string teacherName, std::string courseName)
{
    string path = "Course/" + teacherName;
    fileSys.CreateDir(path);
    path = "Course/" + teacherName + "/" + courseName;
    fileSys.CreateDir(path);
}

void TeachingSystem::DeleteCourse(std::string teacherName, std::string courseName)
{
    string path = "Course/" + teacherName + "/" + courseName;
    fileSys.Delete(path);
}

void TeachingSystem::CreateAssignment(std::string teacherName, std::string courseName, std::string assignment, std::string content)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment;
    fileSys.CreateDir(path);
    fileSys.CreateFile(path + "/Description");
    fileSys.WriteFile(path + "/Description", content);
}

void TeachingSystem::DeleteAssignment(std::string teacherName, std::string courseName, std::string assignment, std::string content)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment;
    fileSys.Delete(path);
}

void TeachingSystem::SubmitAssignment(std::string teacherName, std::string studentName, std::string courseName, std::string assignment, std::string content)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName;
    fileSys.CreateDir(path);
    fileSys.CreateFile(path + "/submission");
    fileSys.CreateFile(path + "/mark");
    fileSys.WriteFile(path + "/submission", content);
}

void TeachingSystem::DeleteSubmission(std::string teacherName, std::string studentName, std::string courseName, std::string assignment, std::string content)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName;
    fileSys.Delete(path);
}

void TeachingSystem::MarkSubmission(std::string teacherName, std::string studentName, std::string courseName, std::string assignment, std::string mark)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName + "/mark";
    fileSys.Delete(path);
    fileSys.CreateFile(path);
    fileSys.WriteFile(path, mark);
}

std::string TeachingSystem::getCourseInfo(std::string teacherName, std::string courseName)
{
    std::string path = "Course/" + teacherName + "/" + courseName;
    std::string courseList = fileSys.getListTree(path);
    return courseList;
}

std::string TeachingSystem::getAssignmentInfo(std::string teacherName, std::string courseName, std::string assignment)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/Description";
    std::string assignmentInfo = fileSys.getFileCont(path);
    return assignmentInfo;
}

std::string TeachingSystem::getSubmissionInfo(std::string teacherName, std::string courseName, std::string assignment, std::string studentName)
{
    string path = "Course/" + teacherName + "/" + courseName + "/" + assignment + "/" + studentName + "/submission";
    std::string subInfo = fileSys.getFileCont(path);
    return subInfo;
}

void TeachingSystem::Backup()
{
    // lock_guard<mutex> lock(courseMutex);
    fileSys.Delete("Backup");
    fileSys.CreateDir("Backup");
    fileSys.Copy("User", "Backup");
    fileSys.Copy("Course", "Backup");
}

void TeachingSystem::Recovery()
{
    // lock_guard<mutex> lock(courseMutex);
    fileSys.Delete("User");
    fileSys.Delete("Course");
    fileSys.Copy("Backup/User", "");
    fileSys.Copy("Backup/Course", "");
}