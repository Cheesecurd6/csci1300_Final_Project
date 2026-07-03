#ifndef CROP_H
#define CROP_H
#include <string>

class Crop {
    private:
    std::string name;
    int daysToGrow;
    int daysGrown;
    bool wateredToday;
    bool dayHasPassed;

    public:
    Crop(std::string n, int d);
    bool getWaterStatus();
    void water();
    void nextDay();
    bool harvestable();


};

#endif