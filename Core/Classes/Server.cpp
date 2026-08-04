#include <iostream>

class Server {
    int port;
public:
    Server(const int& port) : port(port) {
        std::cout << "Server is running on port: " << port << std::endl;
    };
};