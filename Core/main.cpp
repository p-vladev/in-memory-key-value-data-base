#include <iostream>
#include "thread"
#include <string>
#include "./Server/Runtime.cpp"

int main () {

    Runtime rnt;

    std::string input;
    
    while (true) {
        std::getline(std::cin, input);

        if (input == "stop") {
            rnt.Stop();
            break;
        }

        if (!input.empty()) {
            rnt.Execute(input);
        }
    }

    return 0;
}
