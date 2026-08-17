#include <iostream>
#include <unordered_map>
// #include "./Snapshoter/Snapshoter.cpp"
// #include "./Storage/Db.cpp"
#include "./Server/Runtime.cpp"
#include <fstream>
#include <thread>

int main () {
    // Db db;
    // int p = 8080;
    bool running = true;

    std::thread t([&](){
        Runtime rnt;
        
        do {
            std::string msg;

            std::cin >> msg;

            if (msg == "stop") {
                rnt.Stop();

                running = false;
            }

            rnt.Execute(msg);
    
        } while (running);
    });

    t.join();


    // db.Add("name", "Kris");
    // db.Add("sname", "Dreemur");
    // db.Add("age", "15");
    // db.Add("gender", "male");

    // Snapshoter::SaveAsJson("test");

    return 0;
}
