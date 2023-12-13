#include <iostream>
#include "TeachingSystem.h"
using namespace std;

TeachingSystem ts;

int main(){
    string username;
    
    ts.CreateUser("root", "root", "1");
    ts.CreateUser("teacher1", "teacher1", "2");
    ts.CreateUser("teacher2", "teacher3", "2");
    ts.CreateUser("teacher3", "teacher3", "2");
    ts.CreateUser("student1", "student1", "3");
    ts.CreateUser("student2", "student2", "3");
    ts.CreateUser("student3", "student3", "3");

    ts.CreateCourse("teacher1", "Computer-Science");
    ts.CreateCourse("teacher1", "Computer-Vision");

    ts.CreateCourse("teacher2", "NLP");
    ts.CreateCourse("teacher3", "RL");

    ts.CreateAssignment("teacher1", "Computer-Science", "LAB1", "Lab1Content");
    ts.CreateAssignment("teacher1", "Computer-Science", "LAB2", "Lab2Content");
    ts.CreateAssignment("teacher2", "NLP", "LAB1", "Lab1Content");
    ts.CreateAssignment("teacher2", "NLP", "LAB2", "Lab2Content");

    ts.SubmitAssignment("teacher1", "student1", "Computer-Science", "LAB1", "Lab1Content");
    ts.MarkSubmission("teacher1", "student1", "Computer-Science", "LAB1", "99");

    while(true)
    {
        string command0;
        cout << "Please enter 1 to log in and 0 to exit：" << endl;
        cout << "----------------------------------------" << endl;
        cin >> command0;
        if(command0=="0") break;
        else if (command0=="1")
        {
            string current_user = "No_current_user";
            string role;

            cout << ts.ListUser() << endl;
            string password;
            cout << "Username:"; cin  >> username;
            cout << "Password:"; cin  >> password;
            role = ts.getLoginStatus(username, password);

            if(role == "1")
            {
                cout << "----------------------------------------" << endl
                    << "help    -- More avaliable commands" << endl
                    << "0       -- Exit file system" << endl
                    << "1       -- List all users" << endl
                    << "2       -- Show all infomation"<<endl
                    << "3       -- Create a User"<<endl
                    << "4       -- Delete a User "<<endl
                    << "5       -- Create a course "<<endl
                    << "6       -- Delete a course "<<endl
                    << "7       -- Create a assignment "<<endl
                    << "8       -- Delete a assignment "<<endl
                    << "9       -- Create a submission "<<endl
                    << "10      -- Delete a submission "<<endl
                    << "11      -- Mark a submission "<<endl
                    << "12      -- Get course info in list "<<endl
                    << "13      -- Get assignment content "<<endl
                    << "14      -- Get submission content "<<endl
                    << "15      -- Get submission mark "<<endl
                    << "16      -- Backup system "<<endl
                    << "17      -- Recovery system "<<endl
                    << "----------------------------------------" << endl;

                while(true)
                {
                    string command;
                    cout << "Type in the number refer to the specific command:";
                    cin >> command;
                    if (command == "help")
                    {
                        cout << "----------------------------------------" << endl
                        << "help    -- More avaliable commands" << endl
                        << "0       -- Exit file system" << endl
                        << "1       -- List all users" << endl
                        << "2       -- Show all infomation"<<endl
                        << "3       -- Create a User"<<endl
                        << "4       -- Delete a User "<<endl
                        << "5       -- Create a course "<<endl
                        << "6       -- Delete a course "<<endl
                        << "7       -- Create a assignment "<<endl
                        << "8       -- Delete a assignment "<<endl
                        << "9       -- Create a submission "<<endl
                        << "10      -- Delete a submission "<<endl
                        << "11      -- Mark a submission "<<endl
                        << "12      -- Get course info in list "<<endl
                        << "13      -- Get assignment content "<<endl
                        << "14      -- Get submission content "<<endl
                        << "15      -- Get submission mark "<<endl
                        << "16      -- Backup system "<<endl
                        << "17      -- Recovery system "<<endl
                        << "----------------------------------------" << endl;
                    }
                    else if (command == "0")
                    {
                        break;
                    }
                    else if (command == "1")
                    {
                        cout << ts.ListUser() << endl;
                    }
                    else if (command == "2")
                    {
                        cout << ts.ShowAllInfo() << endl;
                    }
                    else if (command == "3")
                    {
                        string newUserName;
                        string newUserPass;
                        string newUserRole;
                        cout << "New username:" ; cin >> newUserName;
                        cout << "New password:" ; cin >> newUserPass;
                        cout << "1 is ADMIN, 2 is TEACHER, 3 is STUDENT." << endl;
                        cout << "New userRole:" ; cin >> newUserRole;

                        ts.CreateUser(newUserName, newUserPass, role);
                    }
                    else if (command == "4")
                    {
                        cout << ts.ListUser() << endl;
                        string nameToDel;
                        cout << "User to be deleted:" ; cin >> nameToDel;
                        ts.DeleteUser(nameToDel);
                    }
                    else if (command == "5")
                    {
                        string teacherName;
                        string newCourseName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> newCourseName;

                        ts.CreateCourse(teacherName, newCourseName);
                    }
                    else if (command == "6")
                    {
                        string teacherName;
                        string newCourseName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> newCourseName;

                        ts.DeleteCourse(teacherName, newCourseName);
                    }
                    else if (command == "7")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        string content;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "content of assiment:" ; cin >> content;

                        ts.CreateAssignment(teacherName, courseName, assignName, content);
                    }
                    else if (command == "8")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        string content;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "content of assiment:" ; cin >> content;

                        ts.DeleteAssignment(teacherName, courseName, assignName, content);
                    }
                    else if (command == "9")
                    {
                        string teacherName;
                        string studentName;
                        string courseName;
                        string assignName;
                        string content;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "student name:" ; cin >> studentName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "content of submission:" ; cin >> content;

                        ts.SubmitAssignment(teacherName, studentName, courseName, assignName, content);
                    }
                    else if (command == "10")
                    {
                        string teacherName;
                        string studentName;
                        string courseName;
                        string assignName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "student name:" ; cin >> studentName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;

                        ts.DeleteSubmission(teacherName, studentName, courseName, assignName);
                    }
                    else if (command == "11")
                    {
                        string teacherName;
                        string studentName;
                        string courseName;
                        string assignName;
                        string mark;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "student name:" ; cin >> studentName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "mark of submission:" ; cin >> mark;

                        ts.MarkSubmission(teacherName, studentName, courseName, assignName, mark);
                    }
                    else if (command == "12")
                    {
                        string teacherName;
                        string courseName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;

                        cout << ts.getCourseInfo(teacherName, courseName) << endl;
                    }
                    else if (command == "13")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;

                        cout << ts.getAssignmentInfo(teacherName, courseName, assignName) << endl;
                    }
                    else if (command == "14")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        string studentName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "student name:" ; cin >> studentName;

                        cout << ts.getSubmissionInfo(teacherName, courseName, assignName, studentName) << endl;
                    }
                    else if (command == "15")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        string studentName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "student name:" ; cin >> studentName;

                        cout << ts.getSubmissionMark(teacherName, courseName, assignName, studentName) << endl;
                    }
                    else if (command == "16")
                    {
                        ts.Backup();
                    }
                    else if (command == "17")
                    {
                        ts.Recovery();
                    }
                    else 
                    {
                        cout << "invalid input." << endl;
                    }
                }
            }
            if(role == "2")
            {
                cout << "----------------------------------------" << endl
                    << "help    -- More avaliable commands" << endl
                    << "0       -- Exit file system" << endl
                    << "1       -- List all users" << endl
                    << "2       -- Create a assignment "<<endl
                    << "3       -- Delete a assignment "<<endl
                    << "4       -- Mark a submission "<<endl
                    << "5       -- Get course info in list "<<endl
                    << "6       -- Get assignment content "<<endl
                    << "7       -- Get submission content "<<endl
                    << "8       -- Get submission mark "<<endl
                    << "----------------------------------------" << endl;
                while(true)
                {
                    string command;
                    cout << "Type in the number refer to the specific command:";
                    cin >> command;
                    if (command == "help")
                    {
                        cout << "----------------------------------------" << endl
                        << "help    -- More avaliable commands" << endl
                        << "0       -- Exit file system" << endl
                        << "1       -- List all users" << endl
                        << "2       -- Create a assignment "<<endl
                        << "3       -- Delete a assignment "<<endl
                        << "4       -- Create a submission "<<endl
                        << "5       -- Delete a submission "<<endl
                        << "6       -- Mark a submission "<<endl
                        << "7       -- Get assignment content "<<endl
                        << "8       -- Get submission content "<<endl
                        << "9       -- Get submission mark "<<endl
                        << "----------------------------------------" << endl;
                    }
                    else if (command == "0")
                    {
                        break;
                    }
                    else if (command == "1")
                    {
                        cout << ts.ListUser() << endl;
                    }
                    else if (command == "2")
                    {
                        string courseName;
                        string assignName;
                        string content;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "content of assiment:" ; cin >> content;

                        ts.CreateAssignment(username, courseName, assignName, content);
                    }
                    else if (command == "3")
                    {
                        string courseName;
                        string assignName;
                        string content;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "content of assiment:" ; cin >> content;

                        ts.DeleteAssignment(username, courseName, assignName, content);
                    }
                    else if (command == "4")
                    {
                        string studentName;
                        string courseName;
                        string assignName;
                        string content;
                        cout << "student name:" ; cin >> studentName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "content:" ; cin >> content;

                        ts.SubmitAssignment(username, studentName, courseName, assignName, content);
                    }
                    else if (command == "5")
                    {
                        string studentName;
                        string courseName;
                        string assignName;
                        cout << "student name:" ; cin >> studentName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;

                        ts.DeleteSubmission(username, studentName, courseName, assignName);
                    }
                    else if (command == "6")
                    {
                        string studentName;
                        string courseName;
                        string assignName;
                        string mark;
                        cout << "student name:" ; cin >> studentName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "mark of submission:" ; cin >> mark;

                        ts.MarkSubmission(username, studentName, courseName, assignName, mark);
                    }
                    else if (command == "7")
                    {
                        string courseName;
                        string assignName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;

                        cout << ts.getAssignmentInfo(username, courseName, assignName) << endl;
                    }
                    else if (command == "8")
                    {
                        string courseName;
                        string assignName;
                        string studentName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "student name:" ; cin >> studentName;

                        cout << ts.getSubmissionInfo(username, courseName, assignName, studentName) << endl;
                    }
                    else if (command == "9")
                    {
                        string courseName;
                        string assignName;
                        string studentName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "student name:" ; cin >> studentName;

                        cout << ts.getSubmissionMark(username, courseName, assignName, studentName) << endl;
                    }
                    else 
                    {
                        cout << "invalid input." << endl;
                    }
                }
            }
            if(role == "3")
            {
                cout << "----------------------------------------" << endl
                    << "help    -- More avaliable commands" << endl
                    << "0       -- Exit file system" << endl
                    << "1       -- Create your submission "<<endl
                    << "2       -- Delete your submission "<<endl
                    << "3       -- Get assignment content "<<endl
                    << "4       -- Get submission content "<<endl
                    << "5       -- Get submission mark "<<endl
                    << "----------------------------------------" << endl;
                while(true)
                {
                    string command;
                    cout << "Type in the number refer to the specific command:";
                    cin >> command;
                    if (command == "help")
                    {
                        cout << "----------------------------------------" << endl
                        << "help    -- More avaliable commands" << endl
                        << "0       -- Exit file system" << endl
                        << "1       -- Create your submission "<<endl
                        << "2       -- Delete your submission "<<endl
                        << "3       -- Get assignment content "<<endl
                        << "4       -- Get submission content "<<endl
                        << "5       -- Get submission mark "<<endl
                        << "----------------------------------------" << endl;
                    }
                    else if (command == "0")
                    {
                        break;
                    }
                    else if (command == "1")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        string content;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "content of submission:" ; cin >> content;

                        ts.SubmitAssignment(teacherName, username, courseName, assignName, content);
                    }
                    else if (command == "2")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;

                        ts.DeleteSubmission(teacherName, username, courseName, assignName);
                    }
                    else if (command == "3")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;

                        cout << ts.getAssignmentInfo(teacherName, courseName, assignName) << endl;
                    }
                    else if (command == "4")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        string studentName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;
                        cout << "student name:" ; cin >> studentName;

                        cout << ts.getSubmissionInfo(teacherName, courseName, assignName, username) << endl;
                    }
                    else if (command == "5")
                    {
                        string teacherName;
                        string courseName;
                        string assignName;
                        cout << "teacher name:" ; cin >> teacherName;
                        cout << "course name:" ; cin >> courseName;
                        cout << "assignment name:" ; cin >> assignName;

                        cout << ts.getSubmissionMark(teacherName, courseName, assignName, username) << endl;
                    }
                    else 
                    {
                        cout << "invalid input." << endl;
                    }
                }
            }
        }
    }
}