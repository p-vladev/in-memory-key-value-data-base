#include <iostream>
#include <array>
#include "ProtocolParser.hpp"
#include "../Storage/Db.hpp"

void ProtocolParser::Parse(const std::string& req) {
    for (size_t i = 0; i < req.length(); i++) {
        buffer[i] = req[i];
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

        res = true;
    }
    else if (args[COMMAND] == "GET") {
        Db::GetValue(args[KEY]);

        res = true;
    }
    else if (args[COMMAND] == "DEL")
    {
        Db::Delete(args[KEY]);

        res = true;
    }
    else {
        res = false;
    }
}

std::string ProtocolParser::Response() {
    return res ? "SUCCESS" : "ERROR";
}