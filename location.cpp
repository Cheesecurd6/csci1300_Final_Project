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


void Location::setPeople(std::vector<Villager> locationPeople) {
    people = locationPeople;
}

void Location::setName(std::string locationName) {
    name = locationName;
}


Location::Location(std::string n, std::vector<Villager> p, int l) {
    name = n;
    people = p;
    luck = l;
}

Player Location::getThePlayer() {
    return thePlayer;
}
