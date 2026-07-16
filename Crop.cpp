#include "Crop.h"
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
    // When the next day comes if the crop has been watered today it'll grow and then go to being unwatered
    // Harvestable is also called to check if the crop is now harvestable
    void Crop::nextDay() {
        if (wateredToday) {
                daysGrown++;
        }
        wateredToday = false;
        harvestable();
    }
    void Crop::harvestable() {
        if(daysGrown >= daysToGrow) {
            h = true;
        }

    }

     bool Crop::getIfHarvestable() {
        return h;
     }