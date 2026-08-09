#include <iostream>
#include <unordered_map>
#include "./Snapshoter/Snapshoter.cpp"
#include "./Storage/Db.cpp"
#include <fstream>

int main () {

    Db db;

    db.Add("name", "Kris");
    db.Add("sname", "Dreemur");
    db.Add("age", "15");
    db.Add("gender", "male");

    Snapshoter::SaveAsJson("test");

    return 0;
}
