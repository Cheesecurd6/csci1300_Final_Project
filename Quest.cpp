#include <string>
#include <vector>
#include <iostream>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "villager.h"
#include "Quest.h"

    
Quest::Quest(std::string d,std::string n, Item i, Item r, bool a, bool c) {
    description = d;
    name = n;
    reward = i;
    isActive = a;
    isCompleted = c;
    requirement = r;
}

Quest::Quest() {
    description = "";
    name = "";
    reward = Item();
    isActive = 0;
    isCompleted = 0;
    requirement = Item();
}
std::string Quest::getDescription() {
    return description;
}
Item Quest::getReward() {
    return reward;
}

Item Quest::getRequirement() {
    return requirement;
}
bool Quest::getIfActive() {
    return isActive;
}
bool Quest::getIfCompleted() {
    return isCompleted;
}

std::string Quest::getName() {
    return name;
}

void Quest::setIfActive(bool a) {
    isActive = a;
}
void Quest::setIfCompleted(bool c) {
    isCompleted = c;
}

