#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <vector>
#include "villager.h"
#include "player.h"

class Location {
    // All game locations inhereit from this class
    public:
    Location(std::string n, std::vector<Villager> p, int l);
    std::string getName() const;
    std::vector<Villager> getPeople() const;
    Player getThePlayer();

    void setPeople(std::vector<Villager> locationPeople);
    void setName(std::string locationName);
    
    protected:
    // The villagers libing there
    std::vector<Villager> people;
    // Locations name
    std::string name;
    // The locations copy of the player
    Player thePlayer;
    // The locations luck
    int luck;

};

#endif