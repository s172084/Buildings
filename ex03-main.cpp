#include <iostream>
#include "ex03-library.h"
using namespace std;

int main() {
    Campus campus = Campus();

    cout << "Initial status:" << endl;
    campus.display();
    cout << endl;
    
    bool result = false;
    cout << "Increasing the height of building B101 by 1 floor...";
    result = campus.expandBuilding("B101", 1);
    cout << (result ? "success" : "failed") << endl;
    cout << "Increasing the height of building B210 by 3 floors...";
    result = campus.expandBuilding("B210", 3);
    cout << (result ? "success" : "failed") << endl;
    cout << "Increasing the height of building B116 by 2 floors...";
    result = campus.expandBuilding("B116", 2);
    cout << (result ? "success" : "failed") << endl;
    
    cout << "Increasing the height of building B402 by 3 floors exceeding the maximum height allowed...";
    result = campus.expandBuilding("B402", 3);
    cout << (result ? "success" : "failed") << endl;

    cout << endl;
    cout << "Current status:" << endl;
    campus.display();
    cout << endl;

    cout << "Names of buildings for administrative staff" << endl;
    campus.printBuildingNames(ADMINISTRATION);
    
    cout << "Names of buildings for students" << endl;
    campus.printBuildingNames(AUDITORIUM);
    
    cout << "Names of buildings for researchers" << endl;
    campus.printBuildingNames(DEPARTMENT);

    cout << "Demolishing buildings for administrative staff...";
    unsigned int demolishedBuildings = campus.demolishBuildings(ADMINISTRATION);
    cout << "demolished " << demolishedBuildings << " buildings" << endl;
    cout << endl;
    cout << "Repurposing buildings B303 and B324 for administrative staff...";

    vector<string> list;
    list.push_back("B303");
    list.push_back("B324");
    campus.repurposeBuildings(list, ADMINISTRATION);
    
    cout << endl;
    cout << "Current status:" << endl;
    campus.display();

    return 0;
}
