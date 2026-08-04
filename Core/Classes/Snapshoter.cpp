#include <iostream>
#include <unordered_map>

class Snapshoter
{

public:
    void SaveAsJson(const std::string& name, const std::unordered_map<std::string, std::string>& db) {
        std::cout << "JSON saved as " << name << std::endl;
    }
};