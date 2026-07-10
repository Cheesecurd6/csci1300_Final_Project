#include <string>
#include <vector>
#include <iostream>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "villager.h"
#include "Quest.h"

    
Quest::Quest(std::string d,std::string n, Item i, bool a, bool c) {
    description = d;
    name = n;
    reward = i;
    isActive = a;
    isCompleted = c;
}

Quest::Quest() {
    description = "";
    reward = Item();
    isActive = 0;
    isCompleted = 0;
}
std::string Quest::getDescription() {
    return description;
}
Item Quest::getReward() {
    return reward;
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