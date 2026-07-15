#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <vector>
#include "villager.h"
#include "player.h"

class Location {
    public:

    Location(std::string n, std::vector<Villager> p, int l);
    std::string getName() const;
    std::vector<Villager> getPeople() const;
    void getNeighboringLocations() const;
    Player getThePlayer();

    void setPeople(std::vector<Villager> locationPeople);
    void setName(std::string locationName);
    void setNeighbors(std::vector<Location> nearbyLocations);
    
    protected:
    std::vector<Villager> people;
    std::string name;
    std::vector<Location> neighbors;
    Player thePlayer;
    int luck;
};

#endif