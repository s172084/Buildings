#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
string Campus::purposeToString(Purpose c)
{
    switch (c)
    {
    case ADMINISTRATION:
        return "administrative staff";
    case DEPARTMENT:
        return "researchers";
    case AUDITORIUM:
        return "students";
    default:
        return "";
    }
}

// Do not modify
Campus::Campus() {
    
    this->maxHeight = 5;
    this->buildings.push_back({"B101", ADMINISTRATION, 3});
    this->buildings.push_back({"B402", ADMINISTRATION, 5});
    this->buildings.push_back({"B403", ADMINISTRATION, 3});
    this->buildings.push_back({"B404", ADMINISTRATION, 4});
    this->buildings.push_back({"B324", ADMINISTRATION, 5});
    this->buildings.push_back({"B210", DEPARTMENT, 2});
    this->buildings.push_back({"B211", DEPARTMENT, 2});
    this->buildings.push_back({"B212", DEPARTMENT, 3});
    this->buildings.push_back({"B116", AUDITORIUM, 2});
    this->buildings.push_back({"B303", AUDITORIUM, 5});
    this->buildings.push_back({"B304", AUDITORIUM, 1});
    this->buildings.push_back({"B305", AUDITORIUM, 3});
    
}

// Task 3(a).  Implement this method
bool Campus::expandBuilding(string name, unsigned int increment) {
    return true;
    
}

// Task 3(b).  Implement this method
void Campus::printBuildingNames(Purpose purpose)
{
	return;
}

// Task 3(c).  Implement this method
unsigned int Campus::demolishBuildings(Purpose purpose) {
    return 0;
}


// Task 3(d).  Implement this method
void Campus::repurposeBuildings(vector<string> names, Purpose newPurpose) {
    return;
}

// Do not modify
void Campus::display() {
    cout << "The campus can have buildings up to " << this->maxHeight << " floors." << endl;
    for (auto it = this->buildings.begin(); it != this->buildings.end(); it++) {
        cout << "Building " << it->name << " ";
        cout << "is for " << purposeToString(it->purpose) << " and it ";
        cout << "has " << it->height << " floors." ;
        cout << endl;
    }
}
