#include "Database.h"
#include <vector>

using namespace std;

TeachingSystem::TeachingSystem()
{
    fileSys.CreateDir("User");
    fileSys.CreateDir("Course");
    // TeachingSystem::CreateUser("root","root", 1);
}

string TeachingSystem::getLoginStatus(string username, string password)
{
    string role = fileSys.getFileCont("User/" + username + "/" + password);

    // if (role == "")
    //     return ComState::ERROR;

    return role;
}

string TeachingSystem::PrintCourse()
{
    vector<string> list = fileSys.getListVector("Course");
    if (list.size() == 0)
    {
        return "There is no course.\n";
    }

    string res = "There are these courses:\n";
    for (int i = 0; i < list.size(); i++)
    {
        res = res + "    " + list[i] + "\n";
    }
    return res;
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

void TeachingSystem::CreateCourse(string courseName)
{
    string path = "Course/" + courseName;
    fileSys.CreateDir(path);
}

void TeachingSystem::DeleteCourse(string courseName)
{
    string path = "Course/" + courseName;
    fileSys.Delete(path);
}

void TeachingSystem::CreateAssignment(string courseName, string assignment, string content)
{
    string path = "Course/" + courseName + "/" + assignment;
    fileSys.CreateDir(path);
    fileSys.CreateDir(path + "/Homework");
    fileSys.CreateFile(path + "/Content");
    fileSys.WriteFile(path + "/Content", content);
}

string TeachingSystem::getHomworkTitles(string courseName, string assignment)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework";
    vector<string> list = fileSys.getListVector(path);
    if (list.size() == 0)
    {
        return "There is no submitted homework.\n";
    }

    string res = "There are these submitted homework:\n";
    for (int i = 0; i < list.size(); i++)
    {
        res = res + "    " + list[i] + "\n";
    }
    return res;
}

string TeachingSystem::getHomeworkContent(string courseName, string assignment, string title)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework/" + title + "/Content";
    return fileSys.getFileCont(path);
}

void TeachingSystem::MarkHomework(string courseName, string assignment, string title, string score)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework/" + title + "/Score";
    fileSys.WriteFile(path, score);
}

string TeachingSystem::getAssignmentTitles(string courseName)
{
    string path = "Course/" + courseName;
    vector<string> list = fileSys.getListVector(path);
    if (list.size() == 0)
    {
        return "There is no assignment.\n";
    }

    string res = "There are these assignments:\n";
    for (int i = 0; i < list.size(); i++)
    {
        res = res + "    " + list[i] + "\n";
    }
    return res;
}

string TeachingSystem::getAssignmentContent(string courseName, string assignment)
{
    string path = "Course/" + courseName + "/" + assignment + "/Content";
    return fileSys.getFileCont(path);
}

void TeachingSystem::SubmitAssignment(string courseName, string assignment, string title, string content)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework/" + title;
    fileSys.Delete(path);
    fileSys.CreateDir(path);
    fileSys.CreateFile(path + "/Score");
    fileSys.CreateFile(path + "/Content");
    fileSys.WriteFile(path + "/Content", content);
}

string TeachingSystem::getScoreInCourse(string courseName, string assignment, string title)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework/" + title + "/Score";
    return fileSys.getFileCont(path);
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