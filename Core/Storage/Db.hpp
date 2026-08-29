#include <iostream>
#include <unordered_map>
#include "../global/InMemoryDb.hpp"

#pragma once

class Db : public InMemoryDb {

    public:
        static void Add(const std::string& k);

        static void Add(const std::string& k, const std::string& v);

        static void Update(const std::string& k, const std::string& v);

        static std::string GetValue(const std::string& k);

        static bool IsExist(const std::string& k);

        static void Delete(const std::string& k);

        static auto GetAll();
};