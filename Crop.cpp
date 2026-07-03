#include "Crop.hpp"
#include <string>

    Crop::Crop(std::string n, int d) {
        name = n;
        daysToGrow = d;
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
    bool harvestable();