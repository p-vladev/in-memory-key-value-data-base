#include <iostream>
#include <thread>
#include "./Server.hpp"
#include "./Client.hpp"

class Runtime {
    int port = 8080;

    Server srv{port};
    Client cln{port};

public:
    Runtime() {
        std::thread serverThread([&]() {
            srv.Run();

            while (true) {
                srv.Recieve();
            }
        });

        serverThread.detach();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        cln.Run();
    }

    Runtime(const int& port) : port(port), srv(port), cln(port) {
        srv.Run();
        cln.Run();
    }

    void Execute(const std::string& input) {
        cln.Send(input);

        // srv.Recieve();
    }

    void Stop() {
        srv.Stop();
        cln.Stop();
    }
};
