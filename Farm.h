#ifndef FARM_H
#define FARM_H
#include <string>
#include <vector>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "villager.h"

class Farm : public Location{
    private:
    std::vector<Crop> parsnips;
    std::vector<Crop> starfruits;
    std::vector<Crop> blueberries;
    Player thePlayer;
    
    public:
    Farm(std::string n, std::vector<Villager> people);
    void plant(int parsnipSeeds, int starfuitSeeds, int blueberrySeeds);
    void harvestParsnips(Item inventory[10],int howManyHarvest);
    void harvestStarfruits(Item inventory[10],int howManyHarvest);
    void harvestBlueberries(Item inventory[10],int howManyHarvest);
    void newDay();
    

    
    Player getThePlayer();

    int getUnwatered(std::vector<Crop> crops);
    int getPlanted(std::vector<Crop> crops);
    int getHarvestable(std::vector<Crop> crops);
    void waterCrops(std::vector<Crop> crops,std::string name);
    void harvestCrops(std::vector<Crop> crops, Item inventory[10], std::string name, std::string description);

    bool farmTerminal(Player p, Item inventory[]);

};

#endif