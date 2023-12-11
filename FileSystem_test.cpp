#include <string.h>
#include <vector>
#include <iostream>
#include "FileSystem.h"
using namespace std;

FileSystem fileSys;

int main()
{
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
                 << "4       -- list in current directory.    (input the path of the dir.)\n"
                 << "5       -- list in tree.                 (input the path of the dir.)\n"
                 << "6       -- read a file.                  (input the path of the file.)\n"
                 << "7       -- write a file.                 (input the path of the file.)\n"
                 << "8       -- copy one directory to another (input the source path and the target path.)\n"
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
            vector<string> list = fileSys.getListVector(path);
            cout << "Directories and files:" << endl;
            cout << fileSys.getList(path) << endl;
            cout << "\nDirectories and files are shown as above." << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "5")
        {
            cout << "Input path:";
            string path;
            cin >> path;
            cout << "Directories and files:" << endl;
            cout << fileSys.getListTree(path) << endl;
            cout << "\nDirectories and files are shown as above." << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "6")
        {
            cout << "Input path:" << endl;
            string path;
            cin >> path;
            cout << "File content is:\n"
                 << fileSys.getFileContent(path) << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else if (command == "7")
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
        else if (command == "8")
        {
            cout<<"Input the Source Path and the target directory."<<endl;
            string SourcePath,targetPAth;
            cout<<"Please enter the Source Path:";
            cin>>SourcePath;
            cout<<"Please enter the target path:";
            cin>>targetPAth;
            fileSys.Copy(SourcePath,targetPAth);
            cout<<"Copied."<<endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else
            cout << "invalid input" << endl;
    }
}