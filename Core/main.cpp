#include <iostream>
#include "./Protocol/ProtocolParser.hpp"

int main () {
    // std::string req = "SET name Kris";

    // ProtocolParser prs;

    // prs.Parse(req);

    // int p = 8080;
    // bool running = true;

    // std::thread t([&](){
    //     Runtime rnt;
        
    //     do {
    //         std::string msg;

    //         std::cin >> msg;

    //         if (msg == "stop") {
    //             rnt.Stop();

    //             running = false;
    //         }

    //         rnt.Execute(msg);
    
    //     } while (running);
    // });

    // t.join();


    // db.Add("name", "Kris");
    // db.Add("sname", "Dreemur");
    // db.Add("age", "15");
    // db.Add("gender", "male");

    // Snapshoter::SaveAsJson("test");

    ProtocolParser pp;

    pp.Parse("SET name Kris");
    pp.Tokenize();
    pp.Validate();
    std::cout << pp.Response() << std::endl;

    pp.Parse("DEL name Kris");
    pp.Tokenize();
    pp.Validate();
    std::cout << pp.Response() << std::endl;

    return 0;
}
