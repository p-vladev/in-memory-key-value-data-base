#include <iostream>
#include "./Server.hpp"
#include "./Client.hpp"

class Runtime {
    int port = 8080;

    Server srv{port};
    Client cln{port};

public:
    Runtime() {
        srv.Run();
        cln.Run();
    }

    Runtime(const int& port) : port(port), srv(port), cln(port) {
        srv.Run();
        cln.Run();
    }

    void Execute(const std::string& msg) {
        cln.Send(msg);

        srv.Recieve();
    }

    void Stop() {
        srv.Stop();
        cln.Stop();
    }
};
