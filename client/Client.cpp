#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include "Client.h"

using namespace std;

Client::Client()
    : sock(-1)
{
    Connect();
}

void Client::Connect()
{
    sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(1234);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
}

void Client::Disconnect()
{
    close(sock);
    sock=-1;
}

void Client::Send(string content)
{
    const char *message = content.data();
    send(sock, message, strlen(message), 0);
}

string Client::Receive()
{
    char buffer[1024];
    ssize_t bytesRead = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytesRead] = '\0';

    return string(buffer);
}