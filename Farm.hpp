#ifndef FARM_H
#define FARM_H
#include <string>
#include <vector>
#include "location.hpp"
#include "Crop.hpp"

class Farm : public Location{
    private:
    std::vector<Crop> parsnips;
    std::vector<Crop> starfruits;
    std::vector<Crop> blueberries;
    
    public:
    void plant(int parsnipSeeds, int starfuitSeeds, int blueberrySeeds);
    void waterParsnips(int cropsToBeWatered, int energy);
    void waterStarfruits(int cropsToBeWatered, int energy);
    void waterBlueberries(int cropsToBeWatered, int energy);

    int getHowManyParsnipsPlanted();
    int getHowManyStarfruitsPlanted();
    int getHowManyBlueberriesPlanted();

    int getHowManyParsnipsUnwatered();
    int getHowManyStarfruitsUnwatered();
    int getHowManyBlueberriesUnwatered();

};

#endif