#ifndef FARM_H
#define FARM_H
#include <string>
#include <vector>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"

class Farm : public Location{
    private:
    std::vector<Crop> parsnips;
    std::vector<Crop> starfruits;
    std::vector<Crop> blueberries;
    Player thePlayer;
    
    public:
    void plant(int parsnipSeeds, int starfuitSeeds, int blueberrySeeds);
    void harvestParsnips(Item inventory[10],int howManyHarvest);
    void harvestStarfruits(Item inventory[10],int howManyHarvest);
    void harvestBlueberries(Item inventory[10],int howManyHarvest);
    void waterParsnips(int cropsToBeWatered);
    void waterStarfruits(int cropsToBeWatered);
    void waterBlueberries(int cropsToBeWatered);

    int getHowManyParsnipsPlanted();
    int getHowManyStarfruitsPlanted();
    int getHowManyBlueberriesPlanted();
    int getHowManyParsnipsHarvestable();
    int getHowManyStarfruitsHarvestable();
    int getHowManyBlueberriesHarvestable();
    
    Player getThePlayer();

    int getHowManyParsnipsUnwatered();
    int getHowManyStarfruitsUnwatered();
    int getHowManyBlueberriesUnwatered();

    bool farmTerminal(Player p, Item inventory[]);

};

#endif