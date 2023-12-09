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
                 << "help       -- more avaliable commands\n"
                 << "exit       -- exit file system\n"
                 << "createdir  -- create a directory.           Provide the path of the new dir.\n"
                 << "createfile -- create a file.                Provide the path of the new file.\n"
                 << "delete     -- delete a directory or a file. Provide the path of the dir or the file.\n"
                 << "list       -- list all directory and file.  Provide the path of the dir.\n"
                 << "read       -- read a file.                  Provide the path of the file.\n"
                 << "write      -- write a file.                 Provide the path of the file.\n"
                 << endl;
        }
        else if (command == "exit")
        {
            break;
        }
        else if (command == "createdir")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            fileSys.CreateDirectory(path);
            cout << "Complete." << endl;
        }
        else if (command == "createfile")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            fileSys.CreateFile(path);
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