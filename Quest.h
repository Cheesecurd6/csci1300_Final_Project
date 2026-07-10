#ifndef QUEST_H
#define QUEST_H
#include <string>
#include <vector>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "villager.h"

class Quest {
    private:
    std::string description;
    std::string name;
    Item reward;
    bool isActive;
    bool isCompleted;

    public:

    Quest(std::string d, std::string n, Item i, bool a, bool c);
    Quest();
    std::string getDescription();
    std::string getName();
    Item getReward();
    bool getIfActive();
    bool getIfCompleted();


    void setIfActive(bool a);
    void setIfCompleted(bool c);
};

#endif