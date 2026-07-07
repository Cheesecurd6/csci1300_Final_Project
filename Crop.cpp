#include "Crop.hpp"
#include <string>

    Crop::Crop(std::string n, int d, bool harvestable) {
        name = n;
        daysToGrow = d;
        h = harvestable; 
        daysGrown = 0;
        wateredToday = false;
    }

    bool Crop::getWaterStatus() {
        return wateredToday;
    }
    void Crop::water() {
        wateredToday = true;
    }
    void Crop::nextDay() {
        if (wateredToday) {
                daysGrown++;
        }
        wateredToday = false;
    }
    void Crop::harvestable() {
        if(daysGrown == daysToGrow) {
            h = true;
        }

    }