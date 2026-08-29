#include <iostream>
#include <unordered_map>
#include "Db.hpp"

void Db::Add(const std::string& k) {
    db.insert({k, "null"});
}

void Db::Add(const std::string& k, const std::string& v) {
    db.insert({k, v});
}

void Db::Update(const std::string& k, const std::string& v) {
    db.at(k) = v;
}

std::string Db::GetValue(const std::string& k) {
    return db.at(k);
}

bool Db::IsExist(const std::string& k) {
    return db.find(k) == db.end() ? false : true;
}

void Db::Delete(const std::string& k) {
    db.erase(k);
}

auto Db::GetAll() {
    return db;
}
