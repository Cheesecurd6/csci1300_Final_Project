#ifndef FARM_H
#define FARM_H
#include <string>
#include <vector>
#include "location.hpp"
#include "Crop.hpp"
#include "player.hpp"
#include "Item.hpp"

class Farm : public Location{
    private:
    std::vector<Crop> parsnips;
    std::vector<Crop> starfruits;
    std::vector<Crop> blueberries;
    Player thePlayer;
    
    public:
    void plant(int parsnipSeeds, int starfuitSeeds, int blueberrySeeds);
    void waterParsnips(int cropsToBeWatered);
    void waterStarfruits(int cropsToBeWatered);
    void waterBlueberries(int cropsToBeWatered);

    int getHowManyParsnipsPlanted();
    int getHowManyStarfruitsPlanted();
    int getHowManyBlueberriesPlanted();
    Player getThePlayer();

    int getHowManyParsnipsUnwatered();
    int getHowManyStarfruitsUnwatered();
    int getHowManyBlueberriesUnwatered();

    void farmTerminal(Player p, Item inventory[]);

};

#endif