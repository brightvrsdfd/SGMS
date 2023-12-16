#include "Server.h"

int main()
{
    TeachingSystem teachingSystem;
    teachingSystem.CreateUser("root", "root", "1");
    teachingSystem.CreateUser("teacher1", "teacher1", "2");
    teachingSystem.CreateUser("student1", "student1", "3");
    teachingSystem.CreateCourse("teacher1", "os");
    teachingSystem.CreateAssignment("teacher1", "os", "lab1", "lab1content");
    teachingSystem.CreateAssignment("teacher1", "os", "lab2", "lab2content");
    teachingSystem.CreateAssignment("teacher1", "os", "lab3", "lab3content");
    Server server(&teachingSystem);
    server.Run();

    return 0;
}