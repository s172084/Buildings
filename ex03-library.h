#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
#include <map>
using namespace std;

enum Purpose { ADMINISTRATION, DEPARTMENT, AUDITORIUM };

struct Building {
    string name;
    Purpose purpose; 
    unsigned int height;
};

class Campus {
private:
    vector<Building> buildings;
    unsigned int maxHeight;
    
    //Existing
    string purposeToString(Purpose c);
public:
    Campus(void);
    bool expandBuilding(string name, unsigned int increment);
    void printBuildingNames(Purpose purpose);
    unsigned int demolishBuildings(Purpose purpose);
    void repurposeBuildings(vector<string> names, Purpose newPurpose);
    
    //Existing
    void display();
};

#endif /* EX03_LIBRARY_H_ */
