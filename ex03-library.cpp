#include "ex03-library.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Do not modify
string Campus::purposeToString(Purpose c){
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
    
        // Initialisation of the pointer.
        // Pointer to the building we're looking for
        Building* buildingPtr = nullptr;
        
        // Search for the building with the given name
        for (int i = 0; i < buildings.size(); i++) {
            if (buildings[i].name == name) {
                buildingPtr = &buildings[i];  // Get address of the building that has a certain name
                break;
            }
        }
        
        // If building not found, return false
        if (buildingPtr == nullptr) {
            return false;
        }
        
        // Calculate new height
        unsigned int newHeight = buildingPtr->height + increment;
        
        // If new height exceeds maximum, return false
        if (newHeight > maxHeight) {
            return false;
        }
        
        // Update the building's height using the pointer
        buildingPtr->height = newHeight;
        return true; 
}




// Task 3(b).  Implement this method

void Campus::printBuildingNames(Purpose purpose) {
    
    // Create a vector of pointers to buildings with matching purpose
    vector<Building*> matchingBuildings;
    
    // Find all buildings with the specified purpose
    for (int i = 0; i < buildings.size(); i++) {
        if (buildings[i].purpose == purpose) {
            matchingBuildings.push_back(&buildings[i]);     // Store address of building
        }
    }
    
    // Sort by height in descending order (tallest first)
    
    for (int i = 0; i < matchingBuildings.size(); i++) {
        for (int j = i + 1; j < matchingBuildings.size(); j++) {
            if (matchingBuildings[j]->height > matchingBuildings[i]->height) {
                // Swap pointers
                Building* temp = matchingBuildings[i];
                matchingBuildings[i] = matchingBuildings[j];
                matchingBuildings[j] = temp;
            }
        }
    }
    
    // Print the sorted buildings
    for (const auto& buildingPtr : matchingBuildings) {
        std::cout << buildingPtr->name << " (" << purposeToString(buildingPtr->purpose) 
        << ") - The Building Height is: " << buildingPtr->height << std::endl;
    }
}
// Doesn't pass the tests because of this ^^^
    

// Task 3(c).  Implement this method
unsigned int Campus::demolishBuildings(Purpose purpose) {
    
    unsigned int count = 0;
    
    auto currentBuilding = buildings.begin();              // Loop through the vector with an iterator
    
    while (currentBuilding != buildings.end()) {
        if (currentBuilding->purpose == purpose) {
            currentBuilding = buildings.erase(currentBuilding); 
            // erase() returns iterator to next element
            count++;
        } else {
            ++currentBuilding;                               // Move to next element only if not erasing
        }
    }
    return count;
}

// Task 3(d).  Implement this method
void Campus::repurposeBuildings(vector<string> names, Purpose newPurpose) {
    // Loop through each building
    for (auto& building : buildings) {
        
                                                 // Check if this building's name is in the names vector
        for (const auto& name : names) {
            if (building.name == name) {
                building.purpose = newPurpose;   // Change the purpose
                break;                           // Found the name, no need to check further
            }
        }
    }
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
        