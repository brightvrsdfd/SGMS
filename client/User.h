#pragma once

#include "Client.h"

class User
{
    private:
        Client cli;

    public:
        User();

        void Login();

    private:
        void helper(std::string);
        void End();

        void UI_A();
        void UI_T();
        void UI_S();

        void Exit();

        // Student
        void SubmitAssignment();
        void DeleteSubmission();
        void getAssignmentInfo();
        void getSubmissionInfo(); 

        // Teacher
        void CreateAssignment();
        void DeleteAssignment();
        void MarkSubmission();
        void getCourseInfo();

        // Administrator
        void CreateUser();
        void DeleteUser();
        void CreateCourse();
        void DeleteCourse();
        void Backup();
        void Recovery();
        void ListUser();
        void ShowAllInfo();
};