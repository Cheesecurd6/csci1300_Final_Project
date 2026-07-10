#include <string>
#include <vector>
#include "location.h"
#include <iostream>
std::string Location::getName() const {
    return name;
}
std::vector<Villager> Location::getPeople() const {
    return people;
}

void Location::getNeighboringLocations() const {
for (unsigned int i = 0; i < neighbors.size(); i++) {
    std::cout << neighbors[i].getName() << ", ";
}
}


void Location::setPeople(std::vector<Villager> locationPeople) {
    people = locationPeople;
}

void Location::setName(std::string locationName) {
    name = locationName;
}

void Location::setNeighbors(std::vector<Location> nearbyLocations) {
    neighbors = nearbyLocations;
}

Location::Location(std::string n, std::vector<Villager> p) {
    name = n;
    people = p;
}
