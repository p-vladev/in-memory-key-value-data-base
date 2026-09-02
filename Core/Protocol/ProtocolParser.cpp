#include <iostream>
#include <array>
#include "ProtocolParser.hpp"
#include "../Storage/Db.hpp"

void ProtocolParser::Parse(const char* req) {
    std::cout << "PARSING: " << req << std::endl;

    for (size_t i = 0; i < 40; i++) {
        buffer[i] = req[i];
        if (req[i] == '\0') {
            break;
        }
    }
}

void ProtocolParser::Tokenize() {
    std::string token = "";
    int currentArg = 0;

    bool isEmpty;

    for (size_t i = 0; i <= std::size(buffer); i++) {

        isEmpty = buffer[i] == '\0';

        if(std::isblank(buffer[i]) || isEmpty) {
            args[currentArg] = token;
            
            currentArg++;
            
            token = "";
                
            if(isEmpty) { break; }

            continue; 
        }
        
        token += buffer[i];
    }
}

void ProtocolParser::Validate() {
    if (args[COMMAND] == "SET") {
        Db::Add(args[KEY], args[VALUE]);

        responseStatus = true;
    }
    else if (args[COMMAND] == "GET") {
        response = Db::GetValue(args[KEY]);
        
        responseStatus = true;
    }
    else if (args[COMMAND] == "DEL")
    {
        Db::Delete(args[KEY]);

        responseStatus = true;
    }
    else {
        for (std::string arg : args) {
            std::cout << arg << '\n';
        }

        responseStatus = false;
    }
}

std::string ProtocolParser::Response() {
    if (responseStatus) { std::cout << "SUCCESS"; } else { std::cout << "ERROR"; }
    
    return response;
}