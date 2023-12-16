#include <iostream>
#include <string>
#include "User.h"

using namespace std;

User::User()
{

}

void User::Login()
{
    while(1)
    {
        string s;

        cli.Send("Login");

        helper("Username");
        helper("Password");

        s=cli.Receive();

        cout << s << endl;

        if(s == "ERROR")
        {
            cout<<"Fail to login. Try again"<<endl;
        }
            
        else if(s=="1"){
            UI_A();}
        else if(s=="2"){
            UI_T();}
        else if(s=="3"){
            UI_S();}

    }
    // if(s=="1")
    //     UI_A();
    // else if(s=="2")
    //     UI_T();
    // else if(s=="3")
    //     UI_S();
}

void User::End()
{
    cout<<"Operation completed."<<endl;
}

void User::helper(string s)
{
    cout<<s<<":";
    string ss;
    cin>>ss;
    cli.Send(ss);
}

void User::UI_A()
{
    cout<<"You are administrator. Here are your options:"<<endl;
    cout << "----------------------------------------" << endl
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
                    << "15      -- Backup system "<<endl
                    << "16      -- Recovery system "<<endl
                    << "----------------------------------------" << endl;
    string s;
    while(1)
    {
        cout<<"Enter the number of the option you want:";
        cin>>s;
        if(s=="0")
        {
            break;
        }
        else if(s=="1")
            ListUser();
        else if(s=="2")
            ShowAllInfo();
        else if(s=="3")
            CreateUser();
        else if(s=="4")
            DeleteUser();
        else if(s=="5")
            CreateCourse();
        else if(s=="6")
            DeleteCourse();
        else if(s=="7")
            CreateAssignment();
        else if(s=="8")
            DeleteAssignment();
        else if(s=="9")
            SubmitAssignment();
        else if(s=="10")
            DeleteSubmission();
        else if(s=="11")
            MarkSubmission();
        else if(s=="12")
            getCourseInfo();
        else if(s=="13")
            getAssignmentInfo();
        else if(s=="14")
            getSubmissionInfo();
        else if(s=="15")
            Backup();
        else if(s=="16")
            Recovery();
        else
            cout<<"Invalid input!"<<endl;
    }
}

void User::UI_T()
{
    cout<<"You are teacher. Here are your options:"<<endl;
    cout << "----------------------------------------" << endl
                    << "help    -- More avaliable commands" << endl
                    << "0       -- Exit file system" << endl
                    << "1       -- Create a assignment "<<endl
                    << "2       -- Delete a assignment "<<endl
                    << "3       -- Mark a submission "<<endl
                    << "4       -- Get course info in list "<<endl
                    << "5       -- Get assignment content "<<endl
                    << "6       -- Get submission content "<<endl
                    << "----------------------------------------" << endl;
    string s;
    while(1)
    {
        cout<<"Enter the number of the option you want:";
        cin>>s;
        if(s=="0")
        {
            break;
        }
        else if(s=="1")
            CreateAssignment();
        else if(s=="2")
            DeleteAssignment();
        else if(s=="3")
            MarkSubmission();
        else if(s=="4")
            getCourseInfo();
        else if(s=="5")
            getAssignmentInfo();
        else if(s=="6")
            getSubmissionInfo();
        else
            cout<<"Invalid input!"<<endl;
    }
}

void User::UI_S()
{
    cout<<"You are student. Here are your options:"<<endl;
    cout << "----------------------------------------" << endl
                    << "help    -- More avaliable commands" << endl
                    << "0       -- Exit file system" << endl
                    << "1       -- Create your submission "<<endl
                    << "2       -- Delete your submission "<<endl
                    << "3       -- Get assignment content "<<endl
                    << "4       -- Get submission content "<<endl
                    << "----------------------------------------" << endl;
    string s;
    while(1)
    {
        cout<<"Enter the number of the option you want:";
        cin>>s;
        if(s=="0")
        {
            break;
        }
        else if(s=="1")
            SubmitAssignment();
        else if(s=="2")
            DeleteSubmission();
        else if(s=="3")
            getAssignmentInfo();
        else if(s=="4")
            getSubmissionInfo();
        else
            cout<<"Invalid input"<<endl;
    }
}

void User::Exit()
{
    cli.Send("Exit");
    cli.Disconnect();
    cout<<"Successfully exit"<<endl<<endl;
}

void User::SubmitAssignment()
{
    cli.Send("SubmitAssignment");

    helper("Teaher's name");
    helper("Student'same");
    helper("The course's name");
    helper("The assignment's name");
    helper("The content of your work");

    End();
}

void User::DeleteSubmission()
{
    cli.Send("DeleteSubmission");

    helper("Teaher's name");
    helper("Student'same");
    helper("The course's name");
    helper("The assignment's name");

    End();
}

void User::getAssignmentInfo()
{
    cli.Send("getAssignmentInfo");

    helper("Teaher's name");
    helper("The course's name");
    helper("The assignment's name");

    cout<<cli.Receive()<<endl;
}

void User::getSubmissionInfo()
{
    cli.Send("getSubmissionInfo");

    helper("Teaher's name");
    helper("Student'same");
    helper("The course's name");
    helper("The assignment's name");

    cout<<cli.Receive()<<endl;
} 

void User::CreateAssignment()
{
    cli.Send("CreateAssignment");

    helper("Teaher's name");
    helper("The course's name");
    helper("The assignment's name");
    helper("The assignment's content");

    End();
}

void User::DeleteAssignment()
{
    cli.Send("DeleteAssignment");

    helper("Teaher's name");
    helper("The course's name");
    helper("The assignment's name");

    End();
}

void User::MarkSubmission()
{
    cli.Send("MarkSubmission");

    helper("Teaher's name");
    helper("Student's name");
    helper("The course's name");
    helper("The assignment's name");
    helper("The mark");

    End();
}

void User::getCourseInfo()
{
    cli.Send("getCourseInfo");

    helper("Teaher's name");
    helper("The course's name");

    cout<<cli.Receive()<<endl;
}

void User::CreateUser()
{
    cli.Send("CreateUser");

    helper("Username");
    helper("Password");
    helper("Role");

    End();
}

void User::DeleteUser()
{
    cli.Send("DeleteUser");

    helper("Username");

    End();
}

void User::CreateCourse()
{
    cli.Send("CreateCourse");

    helper("Teacher's name");
    helper("The course's name");

    End();
}

void User::DeleteCourse()
{
    cli.Send("DeleteCourse");

    helper("Teacher's name");
    helper("The course's name");

    End();
}

void User::Backup()
{
    cli.Send("Backup");

    End();
}

void User::Recovery()
{
    cli.Send("Recovery");

    End();
}

void User::ListUser()
{
    cli.Send("ListUser");

    cout<<cli.Receive()<<endl;
}

void User::ShowAllInfo()
{
    cli.Send("ShowAllInfo");

    cout<<cli.Receive()<<endl;
}