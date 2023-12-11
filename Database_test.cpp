#include <iostream>
#include "Database.h"
using namespace std;

Database database;

int main(){
    
    database.CreateUser("root", "root", "1");
    database.CreateUser("teacher", "teacher", "2");
    database.CreateUser("student", "student", "3");
    // 主循环
    while(true)
    {
        string command0;
        cout<<"Please enter 1 to log in and 0 to exit："<<endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cin >> command0;
        if(command0=="0")
        {
            break;
        }
        else if(command0=="1")
        {
            // 登录界面
            string current_user="No_current_user";

            while (true)
            {
                cout << database.ListUser() << endl;

                string username;
                string password;
                string role;

                cout << "Username:";
                cin  >> username;
                cout << "Password:";
                cin  >> password;
                role = database.CheckLogin(username, password);
                
                if (role == "1") {
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cout << "You are an administrator." << endl;
                    current_user="admin";
                    break;
                    }
                else if (role == "2") {
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cout << "You are an teacher." << endl;
                    current_user="teacher";
                    break;
                    }
                else if (role == "3") {
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cout << "You are an student." << endl;
                    current_user="student";
                    break;
                    }
                else {
                    cout << "user does not exit / wrong username or password /" << endl;
                }
            }
            if(current_user=="admin")
            {
                // admin的权限表
                cout<< "--------------------------------------------------------------------------------" << endl
                    << "help    -- more avaliable commands" << endl
                    << "0       -- exit file system" << endl
                    << "1       -- Create course" << endl
                    << "2       -- Print courses"<<endl
                    << "3       -- Create assignment"<<endl
                    << "4       -- Create User"<<endl
                    << "5       -- Delete User "<<endl
                    << "6       -- Delete course "<<endl
                    << "7       -- List User "<<endl
                    << "8       -- Mark Homework "<<endl
                    << "9       -- Print Assignment Content "<<endl
                    << "10      -- Print Assignment Title "<<endl
                    << "11      -- Print Submitted Homework "<<endl
                    << "12      -- Print Score "<<endl
                    << "13      -- Receive Homework "<<endl
                    << "14      -- Back up "<<endl
                    << "15      -- recorvery "<<endl
                    << "16      -- Submit Homework"<<endl
                    << "--------------------------------------------------------------------------------" << endl;
            }
            if(current_user=="teacher")
            {
                // teacher的权限表
                cout<< "--------------------------------------------------------------------------------" << endl
                    << "help    -- more avaliable commands" << endl
                    << "0       -- exit file system" << endl
                    << "1       -- Create course" << endl
                    << "2       -- Print courses"<<endl
                    << "3       -- Create assignment"<<endl
                    // << "4       -- Create User"<<endl
                    // << "5       -- Delete User "<<endl
                    << "6       -- Delete course "<<endl
                    // << "7       -- List User "<<endl
                    << "8       -- Mark Homework "<<endl
                    << "9       -- Print Assignment Content "<<endl
                    << "10      -- Print Assignment Title "<<endl
                    << "11      -- Print Submitted Homework "<<endl
                    << "12      -- Print Score "<<endl
                    << "13      -- Receive Homework "<<endl
                    // << "14      -- Back up "<<endl
                    // << "15      -- recorvery "<<endl
                    << "16      -- Submit Homework"<<endl
                    << "--------------------------------------------------------------------------------" << endl;
            }
            if(current_user=="student")
            {
                // student的权限表
                cout<< "--------------------------------------------------------------------------------" << endl
                    << "help    -- more avaliable commands" << endl
                    << "0       -- exit file system" << endl
                    // << "1       -- Create course" << endl
                    << "2       -- Print courses"<<endl
                    // << "3       -- Create assignment"<<endl
                    // << "4       -- Create User"<<endl
                    // << "5       -- Delete User "<<endl
                    // << "6       -- Delete course "<<endl
                    // << "7       -- List User "<<endl
                    // << "8       -- Mark Homework "<<endl
                    << "9       -- Print Assignment Content "<<endl
                    << "10      -- Print Assignment Title "<<endl
                    // << "11      -- Print Submitted Homework "<<endl
                    << "12      -- Print Score "<<endl
                    // << "13      -- Receive Homework "<<endl
                    // << "14      -- Back up "<<endl
                    // << "15      -- recorvery "<<endl
                    << "16      -- Submit Homework"<<endl
                    << "--------------------------------------------------------------------------------" << endl;
            }
            // 命令界面
            while(true)
            {
                string command;
                cout<<"Please enter your command.Enter 'help' for help."<<endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                cin >> command;
                if (command == "0")
                {
                    break;
                }
                // Create course
                else if(command == "1")
                {
                    if(current_user != "admin" && current_user != "teacher")
                    {
                    cout<<"Permission denied!"<<endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                    string course_name;
                    cout<<"Please enter the name of the course:"<<endl;
                    cin>> course_name;
                    database.CreateCourse(course_name);
                    cout<<"Course added."<<endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    }

                }
                // Print courses
                else if(command=="2")
                {
                    if(current_user != "admin" && current_user != "teacher"&& current_user != "student")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout<<database.PrintCourse()<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Create assignment
                else if(command=="3")
                {
                    if(current_user != "admin" && current_user != "teacher")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout<<database.PrintCourse()<<endl;
                        string course_name,assignment,content;
                        cout<<"Course name:"<<endl;
                        cin>>course_name;
                        cout<<"assignment name:"<<endl;
                        cin>>assignment;
                        cout<<"Homework content:"<<endl;
                        cin>>content;
                        database.CreateAssignment(course_name,assignment,content);
                        cout<<"Homework created."<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Create User
                else if(command=="4")
                {
                    if(current_user != "admin" )
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {   
                        string new_user;
                        string new_password;
                        string new_role;
                        cout<<"Username:"<<endl;
                        cin>>new_user;
                        cout<<"Password:"<<endl;
                        cin>>new_password;
                        cout<<"Role('1'=admin,'2'=teacher,'3'=student):"<<endl;
                        cin>>new_role;
                        database.CreateUser(new_user,new_password,new_role);
                        cout<<"New User created."<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Delete User
                else if(command=="5")
                {
                    if(current_user != "admin")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string DeletedUser;
                        cout<<"User name to be deleted:"<<endl;
                        cin>>DeletedUser;
                        database.DeleteUser(DeletedUser);
                        cout<<"User deleted."<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Delete course
                else if(command=="6")
                {
                    if(current_user != "admin" && current_user != "teacher")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string DeletedCourse;
                        cout<<"Course to be deleted:"<<endl;
                        cin>>DeletedCourse;
                        database.DeleteCourse(DeletedCourse);
                        cout<<"Course deleted."<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // List User
                else if(command=="7")
                {
                    if(current_user != "admin" )
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << database.ListUser() << endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Mark Homework
                else if(command=="8")
                {
                    if(current_user != "admin" && current_user != "teacher")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string course_name,assignment,title,score;
                        cout<<"Course name:"<<endl;
                        cin>>course_name;
                        cout<<"assignment name:"<<endl;
                        cin>>assignment;
                        cout<<"title:"<<endl;
                        cin>>title;
                        cout<<"The score you want to rate:"<<endl;
                        cin>>score;
                        database.MarkHomework(course_name,assignment,title,score);
                        cout<<"Score complete"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Print Assignment Content
                else if(command=="9")
                {
                    if(current_user != "admin" && current_user != "teacher"&& current_user != "student")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {   string course_name,assignment;
                        cout<<"Course name:"<<endl;
                        cin>>course_name;
                        cout<<"assignment name:"<<endl;
                        cin>>assignment;
                        cout << database.PrintAssignmentContent(course_name,assignment) << endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Print Assignment Title
                else if(command=="10")
                {
                    if(current_user != "admin" && current_user != "teacher"&& current_user!="student")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string course_name;
                        cout<<"Course name:"<<endl;
                        cin>>course_name;
                        cout<<database.PrintAssignmentTitle(course_name)<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Print Submitted Homework
                else if(command=="11")
                {
                    if(current_user != "admin" && current_user != "teacher")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string course_name,assignment;
                        cout<<"Course name:"<<endl;
                        cin>>course_name;
                        cout<<"assignment name:"<<endl;
                        cin>>assignment;
                        cout<<database.PrintSubmittedHomework(course_name,assignment)<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Print Score
                else if(command=="12")
                {
                    if(current_user != "admin" && current_user != "teacher"&& current_user != "student")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string course_name,assignment,title;
                        cout<<"Course name:"<<endl;
                        cin>>course_name;
                        cout<<"assignment name:"<<endl;
                        cin>>assignment;
                        cout<<"Title:"<<endl;
                        cin>>title;
                        cout<<database.PrintScore(course_name,assignment,title)<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Receive Homework
                else if(command=="13")
                {
                    if(current_user != "admin" && current_user != "teacher")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string course_name,assignment,title;
                        cout<<"Course name:"<<endl;
                        cin>>course_name;
                        cout<<"assignment name:"<<endl;
                        cin>>assignment;
                        cout<<"Title:"<<endl;
                        cin>>title;
                        cout<<database.ReceiveHomework(course_name,assignment,title)<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Back up
                else if(command=="14")
                {
                    if(current_user != "admin" )
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        database.Backup();
                        cout<<"Backup complete."<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Recorvery
                else if(command=="15")
                {
                    if(current_user != "admin" )
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string yesorno;
                        cout<<"Are you sure?y/n"<<endl;
                        cin>>yesorno;
                        if(yesorno=="y"){
                           database.Recovery(); 
                           cout<<"Recovery complete."<<endl;
                        }
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // Submit Homework
                else if(command=="16")
                {
                    if(current_user != "admin" && current_user != "teacher"&& current_user != "student")
                    {
                        cout<<"Permission denied!"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        string course_name,assignment,title,content;
                        cout<<"Course name:"<<endl;
                        cin>>course_name;
                        cout<<"assignment name:"<<endl;
                        cin>>assignment;
                        cout<<"Title:"<<endl;
                        cin>>title;
                        cout<<"Please enter the content of your homework:"<<endl;
                        cin>>content;
                        database.SubmitHomework(course_name,assignment,title,content);
                        cout<<"Homework submitted"<<endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                else if(command=="help")
                {
                    if(current_user=="admin")
                    {
                    // admin的权限表
                    cout<< "--------------------------------------------------------------------------------" << endl
                        << "help    -- more avaliable commands" << endl
                        << "0       -- exit file system" << endl
                        << "1       -- Create course" << endl
                        << "2       -- Print courses"<<endl
                        << "3       -- Create assignment"<<endl
                        << "4       -- Create User"<<endl
                        << "5       -- Delete User "<<endl
                        << "6       -- Delete course "<<endl
                        << "7       -- List User "<<endl
                        << "8       -- Mark Homework "<<endl
                        << "9       -- Print Assignment Content "<<endl
                        << "10      -- Print Assignment Title "<<endl
                        << "11      -- Print Submitted Homework "<<endl
                        << "12      -- Print Score "<<endl
                        << "13      -- Receive Homework "<<endl
                        << "14      -- Back up "<<endl
                        << "15      -- recorvery "<<endl
                        << "16      -- Submit Homework"<<endl
                        << "--------------------------------------------------------------------------------" << endl;
                    }
                    if(current_user=="teacher")
                    {
                    // teacher的权限表
                    cout<< "--------------------------------------------------------------------------------" << endl
                        << "help    -- more avaliable commands" << endl
                        << "0       -- exit file system" << endl
                        << "1       -- Create course" << endl
                        << "2       -- Print courses"<<endl
                        << "3       -- Create assignment"<<endl
                        // << "4       -- Create User"<<endl
                        // << "5       -- Delete User "<<endl
                        << "6       -- Delete course "<<endl
                        // << "7       -- List User "<<endl
                        << "8       -- Mark Homework "<<endl
                        << "9       -- Print Assignment Content "<<endl
                        << "10      -- Print Assignment Title "<<endl
                        << "11      -- Print Submitted Homework "<<endl
                        << "12      -- Print Score "<<endl
                        << "13      -- Receive Homework "<<endl
                        // << "14      -- Back up "<<endl
                        // << "15      -- recorvery "<<endl
                        << "16      -- Submit Homework"<<endl
                        << "--------------------------------------------------------------------------------" << endl;
                    }
                    if(current_user=="student")
                    {
                    // student的权限表
                    cout<< "--------------------------------------------------------------------------------" << endl
                        << "help    -- more avaliable commands" << endl
                        << "0       -- exit file system" << endl
                        // << "1       -- Create course" << endl
                        << "2       -- Print courses"<<endl
                        // << "3       -- Create assignment"<<endl
                        // << "4       -- Create User"<<endl
                        // << "5       -- Delete User "<<endl
                        // << "6       -- Delete course "<<endl
                        // << "7       -- List User "<<endl
                        // << "8       -- Mark Homework "<<endl
                        << "9       -- Print Assignment Content "<<endl
                        << "10      -- Print Assignment Title "<<endl
                        // << "11      -- Print Submitted Homework "<<endl
                        << "12      -- Print Score "<<endl
                        // << "13      -- Receive Homework "<<endl
                        // << "14      -- Back up "<<endl
                        // << "15      -- recorvery "<<endl
                        << "16      -- Submit Homework"<<endl
                        << "--------------------------------------------------------------------------------" << endl;
                    }
                }
                // else if(command == "check"){
                //     string path;
                //     cout<<"Path:"<<endl;
                //     cin>>path;
                //     database.CheckAll(path);
                // }
                else
                {
                    cout<<"Invalid command!"<<endl;
                }
                

            }
        }
        else
        {
            cout<<"Invalid command!"<<endl;
        }
    }
}
