#include <string>
#include <vector>
#include "location.hpp"
#include <iostream>
std::string Location::getName() const {
    return name;
}
void Location::getPeople() const {
    for (unsigned int i = 0; i < people.size(); i++) {
        std::cout << people[i] << ", ";
    }
    std::cout << "are here" << std::endl;
}

void Location::getNeighboringLocations() const {
for (unsigned int i = 0; i < neighbors.size(); i++) {
    std::cout << neighbors[i].getName() << ", ";
}
}


void Location::setPeople(std::vector<std::string> locationPeople) {
    people = locationPeople;
}

void Location::setName(std::string locationName) {
    name = locationName;
}

void Location::setNeighbors(std::vector<Location> nearbyLocations) {
    neighbors = nearbyLocations;
}
