#include <iostream>
#include <unordered_map>

class Db {
    std::unordered_map<std::string, std::string> db;

    public:
        void Add(const std::string& k) {
            db.insert({k, "null"});
        }

        void Add(const std::string& k, const std::string& v) {
            db.insert({k, v});
        }

        void Update(const std::string& k, const std::string& v) {
            db.at(k) = v;
        }

        std::string GetValue(const std::string& k) const {
            return db.at(k);
        }

        bool IsExist(const std::string& k) const {
            return db.find(k) == db.end() ? false : true;
        }

        void Delete(const std::string& k) {
            db.erase(k);
        }
};