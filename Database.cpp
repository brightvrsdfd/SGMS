#include "Database.h"
#include <vector>

using namespace std;

Database::Database()
{
    fileSys.CreateDirectory("User");
    fileSys.CreateDirectory("Course");
    // Database::CreateUser("root","root", 1);
}

string Database::getLoginStatus(string username, string password)
{
    string role = fileSys.getFileContent("User/" + username + "/" + password);

    // if (role == "")
    //     return ComState::ERROR;

    return role;
}

string Database::PrintCourse()
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

string Database::ListUser()
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

void Database::CreateUser(string username, string password, string role)
{
    string path = "User/" + username;
    fileSys.CreateDirectory(path);

    path = path + "/" + password;
    fileSys.CreateFile(path);

    fileSys.WriteFile(path, role);

    // fileSys.WriteFile(path, string(1, char(role)));
}

void Database::DeleteUser(string username)
{
    string path = "User/" + username;
    fileSys.Delete(path);
}

void Database::CreateCourse(string courseName)
{
    string path = "Course/" + courseName;
    fileSys.CreateDirectory(path);
}

void Database::DeleteCourse(string courseName)
{
    string path = "Course/" + courseName;
    fileSys.Delete(path);
}

void Database::CreateAssignment(string courseName, string assignment, string content)
{
    string path = "Course/" + courseName + "/" + assignment;
    fileSys.CreateDirectory(path);
    fileSys.CreateDirectory(path + "/Homework");
    fileSys.CreateFile(path + "/Content");
    fileSys.WriteFile(path + "/Content", content);
}

string Database::getHomworkTitles(string courseName, string assignment)
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

string Database::getHomeworkContent(string courseName, string assignment, string title)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework/" + title + "/Content";
    return fileSys.getFileContent(path);
}

void Database::MarkHomework(string courseName, string assignment, string title, string score)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework/" + title + "/Score";
    fileSys.WriteFile(path, score);
}

string Database::getAssignmentTitles(string courseName)
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

string Database::getAssignmentContent(string courseName, string assignment)
{
    string path = "Course/" + courseName + "/" + assignment + "/Content";
    return fileSys.getFileContent(path);
}

void Database::SubmitAssignment(string courseName, string assignment, string title, string content)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework/" + title;
    fileSys.Delete(path);
    fileSys.CreateDirectory(path);
    fileSys.CreateFile(path + "/Score");
    fileSys.CreateFile(path + "/Content");
    fileSys.WriteFile(path + "/Content", content);
}

string Database::getScoreInCourse(string courseName, string assignment, string title)
{
    string path = "Course/" + courseName + "/" + assignment + "/Homework/" + title + "/Score";
    return fileSys.getFileContent(path);
}

void Database::Backup()
{
    // lock_guard<mutex> lock(courseMutex);
    fileSys.Delete("Backup");
    fileSys.CreateDirectory("Backup");
    fileSys.Copy("User", "Backup");
    fileSys.Copy("Course", "Backup");
}

void Database::Recovery()
{
    // lock_guard<mutex> lock(courseMutex);
    fileSys.Delete("User");
    fileSys.Delete("Course");
    fileSys.Copy("Backup/User", "");
    fileSys.Copy("Backup/Course", "");
}