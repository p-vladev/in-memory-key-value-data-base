#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../global/InMemoryDb.hpp"
#include <exception>

class Snapshoter : public InMemoryDb {

public:
    void TakeSnapshot() {}

    void SaveToDb(const std::string& url) {
        std::cout << "Saved to " << url << std::endl;
    }

    static auto SaveAsJson(const std::string& name) {
        std::fstream file;

        file.open(name + ".json", std::ios::in | std::ios::out | std::ios::trunc);

        if (!file.is_open())
        {
            std::cout << "Error in creating file!" << std::endl;
        }

        size_t i = 1;

        file << "{" << std::endl;

        for(auto it = db.begin(); it != db.end(); it++) {
            file << "\t" << "\"" << it->first << "\": \"" << it->second << "\"";

            db.size() != i ? file << "," << std::endl : file << std::endl;
           
            i++;
        }
        
        file << "}" << std::endl;

        file.close();

        std::cout << "JSON saved as " << name << std::endl;
    }
};