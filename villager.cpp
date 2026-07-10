#include <iostream>
#include "villager.h"

Villager::Villager(std::string d,std::string n,std::string q) {
    name = n;
    description = d;
    quest = q;
}
std::string Villager::getDescription() const {
    return description;
}
std::string Villager::getName() const {
    return name;
}
std::string Villager::getQuest() const {
    return quest;
}
bool Villager::getQuestResult() const {
    return questResult;
}

void Villager::setDescription(std::string vDescription) {
    description = vDescription;
}
void Villager::setName(std::string vName) {
    name = vName;
}
void Villager::setQuest(std::string vQuest) {
    quest = vQuest;
}
void Villager::setQuestResult(bool result) {
    questResult = result;
}
