#include <iostream>
#include "Database.h"
using namespace std;

Database database;

int main(){
    database.CreateUser("root", "root", "1");
    database.CreateUser("teacher", "teacher", "2");
    database.CreateUser("student", "student", "3");

    cout << "--------------------------------------------------------------------------------" << endl
    << "help    -- more avaliable commands" << endl
    << "0       -- exit file system" << endl
    << "1       -- login" << endl
    << "--------------------------------------------------------------------------------" << endl;

    while (true)
    {
        string command;
        cin >> command;
        if (command == "0")
        {
            break;
        }
        else if (command == "1")
        {   
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
                cout << role << endl;
                
                if (role == "1") {
                    cout << "You are an administrator." << endl;
                    }
                else if (role == "2") {
                    cout << "You are an teacher." << endl;
                    }
                else if (role == "3") {
                    cout << "You are an student." << endl;
                    }
                else {
                    cout << "user does not exit / wrong username or password /" << endl;
                }
            }            
        }
    }
}