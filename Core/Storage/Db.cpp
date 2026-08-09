#include <iostream>
#include <unordered_map>
#include "../global/InMemoryDb.hpp"

class Db : public InMemoryDb {

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

        auto GetAll() const {
            return db;
        }
};