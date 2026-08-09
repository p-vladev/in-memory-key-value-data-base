#include <iostream>
#include <unordered_map>

#pragma once

class InMemoryDb {
    protected:
        static std::unordered_map<std::string, std::string> db;
};