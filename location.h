#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <vector>
#include "villager.h"

class Location {
    public:

    Location(std::string n, std::vector<Villager> p);
    std::string getName() const;
    void getPeople() const;
    void getNeighboringLocations() const;

    void setPeople(std::vector<Villager> locationPeople);
    void setName(std::string locationName);
    void setNeighbors(std::vector<Location> nearbyLocations);
    
    protected:
    std::vector<Villager> people;
    std::string name;
    std::vector<Location> neighbors;
};

#endif