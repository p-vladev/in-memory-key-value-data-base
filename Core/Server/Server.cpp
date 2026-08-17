#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <unordered_map>
#include "Server.hpp"
#include <thread>

Server::Server(const int& port) : port(port) { }

void Server::Run() {
    std::cout << "Server is running on port: " << port << std::endl;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    clientSocket = accept(serverSocket, nullptr, nullptr);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    listen(serverSocket, 5);
}

void Server::Recieve () {
    recv(clientSocket, buffer, sizeof(buffer), 0);

    std::cout << "Message from client: " << std::endl;
    
    // std::thread([&]() {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //     std::cout << buffer << std::endl;
    // }).detach(); 

    std::cout << buffer << std::endl;
}

void Server::Stop() {
    close(clientSocket);
}