#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#pragma once

class Client {
    int port;

    int clientSocket;

    sockaddr_in serverAddress;

public:
    Client(const int& port);

    void Run();

    void Send(const std::string& msg);

    void Stop();
};