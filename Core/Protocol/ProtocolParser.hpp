#include <iostream>
#include <array>
// #include "../Storage/Db.cpp"

#pragma once

class ProtocolParser {
    char buffer[1024] = {0};

    std::array<std::string, 3> args;

    const int COMMAND = 0;
    const int KEY = 1;
    const int VALUE = 2;

    bool res;

    // Db db;

public:
    void Parse(const std::string& req);
    
    void Tokenize();
    
    void Validate();

    std::string Response();
};