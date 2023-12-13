#pragma once 

#include "TeachingSystem.h"
#include<string>

class Server
{
    private:
        TeachingSystem* ts;

    public:
        Server(TeachingSystem*);
        void Run();

    private:
        void Handle(std::string,int);
        void Send(std::string,int);
        std::string Receive(int);
        void Login(int);

        // Student
        void SubmitAssignment(int);
        void DeleteSubmission(int);
        void getAssignmentInfo(int);
        void getSubmissionInfo(int); 

        // Teacher
        void CreateAssignment(int);
        void DeleteAssignment(int);
        void MarkSubmission(int);
        void getCourseInfo(int);

        // Administrator
        void CreateUser(int);
        void DeleteUser(int);
        void CreateCourse(int);
        void DeleteCourse(int);
        void Backup(int);
        void Recovery(int);
        void ListUser(int);
        void ShowAllInfo(int);
};