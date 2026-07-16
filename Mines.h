#ifndef MINES_H
#define MINES_H
#include "location.h"
#include <string>
#include <vector>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "villager.h"
#include "Quest.h"

class Mines : public Location {
    
    private:
    Player thePlayer;
    public:
    void buy(Item inventory[10], std::string name, std::string description, int price);
    void sell(Item inventory[10], std::string name, int value);
    bool addItem(Item inventory[10], Item questReward);
    void Mine (Item inventory[]);
    bool searchPlayerInventory(Item questItem, Item inventory[10]);
    void questCheck(int p, Quest playerQuests[9], Item inventory[10]);
    bool mineTerminal(Player p, Item inventory[], Quest playerQuests[], int bundleTracker[]);
    Mines(std::string n, std::vector<Villager> people, int l);
    Player getThePlayer();

};


#endif