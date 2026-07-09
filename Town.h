#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <vector>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"

class Town : public Location{

    void store();
    bool townTerminal(Player p, int inventory[10]);

};

#endif