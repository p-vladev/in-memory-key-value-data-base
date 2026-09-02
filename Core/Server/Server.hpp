#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "../Protocol/ProtocolParser.hpp"

class Server {
    int port;

    char buffer[1024] = {0};

    int serverSocket;

    sockaddr_in serverAddress;

    int clientSocket;

    ProtocolParser pp;
public:
    Server(const int& port);

    void Run();

    void Recieve();

    void Stop();
};