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
    Player getThePlayer();
    bool townTerminal(Player p, Item inventory[10], Quest playerQuests[10]);
    bool searchPlayerInventory(Item questItem, Item inventory[10]);
    Town(std::string n, std::vector<Villager> people);

    private:
    Player thePlayer;

};

#endif