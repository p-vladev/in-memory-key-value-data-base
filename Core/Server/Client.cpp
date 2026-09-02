#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include "Client.hpp"

Client::Client(const int& port) : port(port) { }

void Client::Run() {
    std::cout << "Clinet is running on port: " << port << std::endl;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
}

void Client::Send(const std::string& input) {
    // std::cout << "CLIENT SENDING: " << msg << std::endl;
    
    send(clientSocket, input.c_str(), input.length(), 0);
}

void Client::Stop() {
    close(clientSocket);
}