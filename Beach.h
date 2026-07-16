#ifndef BEACH_H
#define BEACH_H
#include <string>
#include <vector>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "villager.h"
#include "Quest.h"
class Beach : public Location {

    public:
    bool beachTerminal(Player p, Item inventory[], Quest playerQuests[], int bundleTracker[]);
    void buy(Item inventory[10], std::string name, std::string description, int price);
    void sell(Item inventory[10], std::string name, int value);
    bool addItem(Item inventory[10], Item questReward);
    bool searchPlayerInventory(Item questItem, Item inventory[10]);
    void questCheck(int p, Quest playerQuests[], Item inventory[10]);
    void Fish (Item inventory[]);
    Beach(std::string n, std::vector<Villager> people, int l);
};
#endif