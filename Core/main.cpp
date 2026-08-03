#include <iostream>
#include <map>
#include "./Classes/Db.cpp"

int main(){
    Db db;

    db.Add("Name", "Kris");
    db.Add("Name", "Sussie");
    db.Add("Name", "Ralsei");
    db.Add("Name", "Dess");
    db.Add("Name", "Asgore");
    db.Add("Name", "Frisk");
    std::cout << db.GetValue("Name");

    return 0;
}
