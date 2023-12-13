#include "Server.h"

int main()
{
    TeachingSystem teachingSystem;
    teachingSystem.CreateUser("root", "root", "1");
    teachingSystem.CreateUser("teacher1", "teacher1", "2");
    teachingSystem.CreateUser("student1", "student1", "3");
    Server server(&teachingSystem);
    server.Run();

    return 0;
}