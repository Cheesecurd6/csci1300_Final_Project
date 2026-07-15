#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <vector>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "Quest.h"

class Town : public Location{
    public:
    void buy(Item inventory[10], std::string name, std::string description, int price);
    void sell(Item inventory[10], std::string name, int value);
    bool addItem(Item inventory[10], Item questReward);
    bool searchPlayerInventory(Item questItem, Item inventory[10]);
    void questCheck(int p, Quest playerQuests[10], Item inventory[10]);
    bool townTerminal(Player p, Item inventory[10], Quest playerQuests[10], int bundleTracker[]);
    void bundleCheck(int q, Quest playerQuests[10], Item inventory[10]);
    void bundlePlanner(Quest playerQuests[10], int bundleTracker[]);
    Town(std::string n, std::vector<Villager> people, int l);


};

#endif