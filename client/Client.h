#pragma once

#include<string>

class Client
{
    private:
        int sock;

    public:
        Client();

        void Connect();
        void Disconnect();

        void Send(std::string content);
        std::string Receive();
};