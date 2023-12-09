#include <string.h>
#include <vector>
#include <iostream>
#include "FileSystem.h"
using namespace std;

int main()
{
    FileSystem fileSys;

    cout << "Input \"help\" to get help, or input other valid command. Case sensitive." << endl;
    while (true)
    {
        string command;
        cin >> command;
        if (command == "help")
        {
            cout << endl
                 << "help   -- get help\n"
                 << "exit   -- exit system\n"
                 << "create -- create a directory or file. Provide the path along with the name of the file you try to create.\n"
                 << "delete -- delete the specified directory or file\n"
                 << "list   -- print all directory or file names in specified directory\n"
                 << "read   -- read the specified file\n"
                 << "write  -- write to he specified file\n"
                 << endl;
        }
        else if (command == "exit")
        {
            break;
        }
        else if (command == "create")
        {
            cout << "Which type do you want to create? (0:Directory, 1:File)" << endl;
            int isFile;
            cin >> isFile;
            if (isFile != 0 && isFile != 1){
                cout << "invalid input" << endl;
                break;
            }
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            if (isFile)
                fileSys.CreateFile(path);
            else
                fileSys.CreateDirectory(path);
            cout << "Complete." << endl;
        }
        else if (command == "delete")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            fileSys.Delete(path);
            cout << "Complete." << endl;
        }
        else if (command == "list")
        {
            cout << "Input path:";
            string path;
            cin >> path;
            vector<string> list = fileSys.List(path);
            cout << "There are directories and files:" << endl;
            for (int i = 0; i < list.size(); i++)
            {
                cout << list[i] << endl;
            }
            cout << "\nComplete." << endl;
        }
        else if (command == "read")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            cout << "File content is:\n"
                 << fileSys.ReadFile(path) << endl;
            cout << "\nComplete." << endl;
        }
        else if (command == "write")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            cout << "Input content:" << endl;
            string content;
            cin >> content;
            fileSys.WriteFile(path, content);
            cout << "Complete." << endl;
        }
        else
            cout << "invalid input" << endl;
    }
}