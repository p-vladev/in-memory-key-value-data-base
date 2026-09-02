#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <unordered_map>
#include <thread>
#include "Server.hpp"

Server::Server(const int& port) : port(port) { }

void Server::Run() {
    std::cout << "Server is running on port: " << port << std::endl;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    listen(serverSocket, 5);
    
    clientSocket = accept(serverSocket, nullptr, nullptr);

}

void Server::Recieve () {
    int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);

    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
    } else {
        std::cout << "Connection closed or error" << std::endl;
        return;
    }

    pp.Parse(buffer);

    pp.Tokenize();
    pp.Validate();

    std::cout << pp.Response() << std::endl;
}

void Server::Stop() {
    close(clientSocket);
}