#include "Server.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <string>

using namespace std;

Server::Server(TeachingSystem* Ts):ts(Ts){}

void Server::Run()
{
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int clnt_sock;
	//初始化socket元素
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(1234);

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 20);
    signal(SIGCHLD,SIG_IGN);

    struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);

    while(1)
    {
        clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        if(fork()==0)
        {
            close(serv_sock);
            cout<<"A new client is connected"<<endl;
            while(1)
            {
                string s=Receive(clnt_sock);
                if(s=="Exit")
                {
                    cout<<"A client is disconneted"<<endl;
                    close(clnt_sock);
                    exit(0);
                }
                else
                    Handle(s,clnt_sock);
            }
        }
        close(clnt_sock);
    }
    close(serv_sock);
}

void Server::Send(string content, int clientSocket)
{
    const char *message = content.data();
    ssize_t bytesSent = send(clientSocket, message, strlen(message), 0);
    if (bytesSent == -1)
    {
        cerr << "Failed to send data to server." << endl;
    }
}

string Server::Receive(int clientSocket)
{
    char buffer[1024];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1)
    {
        cerr << "Failed to receive data from client." << endl;
        return "";
    }
    buffer[bytesRead] = '\0';

    return string(buffer);
}

void Server::Handle(string s,int clnt_sock)
{
    if(s=="Login")
        Login(clnt_sock);
    else if(s=="ListUser")
        ListUser(clnt_sock);
    else if(s=="ShowAllInfo")
        ShowAllInfo(clnt_sock);
    else if(s=="CreateUser")
        CreateUser(clnt_sock);
    else if(s=="DeleteUser")
        DeleteUser(clnt_sock);
    else if(s=="CreateCourse") 
        CreateCourse(clnt_sock);
    else if(s=="DeleteCourse")
        DeleteCourse(clnt_sock);
    else if(s=="CreateAssignment")
        CreateAssignment(clnt_sock);
    else if(s=="DeleteAssignment")
        DeleteAssignment(clnt_sock);
    else if(s=="SubmitAssignment")
        SubmitAssignment(clnt_sock);
    else if(s=="DeleteSubmission")
        DeleteSubmission(clnt_sock);
    else if(s=="getAssignmentInfo")
        getAssignmentInfo(clnt_sock);
    else if(s=="getSubmissionInfo")
        getSubmissionInfo(clnt_sock);
    else if(s=="CreateAssignment")
        CreateAssignment(clnt_sock);
    else if(s=="DeleteAssignment")
        DeleteAssignment(clnt_sock);
    else if(s=="MarkSubmission")
        MarkSubmission(clnt_sock);
    else if(s=="getCourseInfo")
        getCourseInfo(clnt_sock);
    else if(s=="CreateUser")
        CreateUser(clnt_sock);
    else if(s=="DeleteUser")
        DeleteUser(clnt_sock);
    else if(s=="CreateCourse")
        CreateCourse(clnt_sock);
    else if(s=="DeleteCourse")
        DeleteCourse(clnt_sock);
    else if(s=="Backup")
        Backup(clnt_sock);
    else if(s=="Recovery")
        Recovery(clnt_sock);
    else if(s=="ListUser")
        ListUser(clnt_sock);
    else if(s=="ShowAllInfo")
        ShowAllInfo(clnt_sock);
}

void Server::Login(int clnt_sock)
{
    string username=Receive(clnt_sock);
    string password=Receive(clnt_sock);

    string role=ts->getLoginStatus(username,password);
    Send(role,clnt_sock);
}

void Server::SubmitAssignment(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string sn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);
    string an=Receive(clnt_sock);
    string content=Receive(clnt_sock);

    ts->SubmitAssignment(tn,sn,cn,an,content);
}

void Server::DeleteSubmission(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string sn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);
    string an=Receive(clnt_sock);

    ts->DeleteSubmission(tn,sn,cn,an);
}

void Server::getAssignmentInfo(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);
    string an=Receive(clnt_sock);

    string ret=ts->getAssignmentInfo(tn,cn,an);
    Send(ret,clnt_sock);
}

void Server::getSubmissionInfo(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string sn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);
    string an=Receive(clnt_sock);

    string ret=ts->getSubmissionInfo(tn,cn,an,sn);
    Send(ret,clnt_sock);
} 

void Server::CreateAssignment(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);
    string an=Receive(clnt_sock);
    string content=Receive(clnt_sock);

    ts->CreateAssignment(tn,cn,an,content);
}

void Server::DeleteAssignment(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);
    string an=Receive(clnt_sock);

    ts->DeleteAssignment(tn,cn,an);
}

void Server::MarkSubmission(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string sn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);
    string an=Receive(clnt_sock);
    string m=Receive(clnt_sock);

    ts->MarkSubmission(tn,sn,cn,an,m);
}

void Server::getCourseInfo(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);

    string ret=ts->getCourseInfo(tn,cn);
    Send(ret,clnt_sock);
}

void Server::CreateUser(int clnt_sock)
{
    string username=Receive(clnt_sock);
    string password=Receive(clnt_sock);
    string role=Receive(clnt_sock);

    ts->CreateUser(username,password,role);
}

void Server::DeleteUser(int clnt_sock)
{
    string username=Receive(clnt_sock);

    ts->DeleteUser(username);
}

void Server::CreateCourse(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);

    ts->CreateCourse(tn,cn);
}

void Server::DeleteCourse(int clnt_sock)
{
    string tn=Receive(clnt_sock);
    string cn=Receive(clnt_sock);

    ts->DeleteCourse(tn,cn);
}

void Server::Backup(int clnt_sock)
{
    ts->Backup();
}

void Server::Recovery(int clnt_sock)
{
    ts->Recovery();
}

void Server::ListUser(int clnt_sock)
{
    string ret=ts->ListUser();
    Send(ret,clnt_sock);
}

void Server::ShowAllInfo(int clnt_sock)
{
    string ret=ts->ShowAllInfo();
    Send(ret,clnt_sock);
}