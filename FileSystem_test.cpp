#include <string.h>
#include <vector>
#include <iostream>
#include "FileSystem.h"
using namespace std;

int main()
{
    FileSystem fileSys;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Input \"help\" to get help, or input other valid command. Enter 0 to exit the system" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    while (true)
    {
        string command;
        cin >> command;
        if (command == "help")
        {
            cout << "--------------------------------------------------------------------------------" << endl
                 << "help    -- more avaliable commands\n"
                 << "0       -- exit file system\n"
                 << "1       -- create a directory.           (input the path of the new dir.)\n"
                 << "2       -- create a file.                (input the path of the new file.)\n"
                 << "3       -- delete a directory or a file. (input the path of the dir or the file.)\n"
                 << "4       -- list all directory and file.  (input the path of the dir.)\n"
                 << "5       -- read a file.                  (input the path of the file.)\n"
                 << "6       -- write a file.                 (input the path of the file.)\n"
                 << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "0")
        {
            break;
        }
        else if (command == "1")
        {
            cout << "Input path:";
            string path;
            cin >> path;
            fileSys.CreateDirectory(path);
            cout << "\"" << path << "\" is created." << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "2")
        {
            cout << "Input path:";
            string path;
            cin >> path;
            fileSys.CreateFile(path);
            cout << "\"" << path << "\" is created." << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "3")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            fileSys.Delete(path);
            cout << "\"" << path << "\" is deleted." << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "4")
        {
            cout << "Input path:";
            string path;
            cin >> path;
            vector<string> list = fileSys.List(path);
            cout << "Directories and files:" << endl;
            for (int i = 0; i < list.size(); i++)
            {
                cout << list[i] << endl;
            }
            cout << "\nDirectories and files are shown as above." << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "5")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            cout << "File content is:\n"
                 << fileSys.ReadFile(path) << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "6")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            cout << "Input content:" << endl;
            string content;
            cin >> content;
            fileSys.WriteFile(path, content);
            cout << "\"" << path << "\" file content is modified." << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else
            cout << "invalid input" << endl;
    }
}