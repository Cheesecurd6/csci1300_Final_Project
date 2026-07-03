#include <string>
#include <vector>
#include <iostream>
#include "Farm.hpp"
#include "Crop.hpp"

// Try/Catch statement with the input of how many crops watered.
    void Farm::plant(int parsnipSeeds, int starfuitSeeds, int blueberrySeeds) {
        for(int i = 0; i < parsnipSeeds; i++) {
            parsnips.push_back(Crop("parsnip" , 2));
        }

        for(int i = 0; i < starfuitSeeds; i++) {
            starfruits.push_back(Crop("starfruit" , 4));
        }

        for(int i = 0; i < blueberrySeeds; i++) {
            blueberries.push_back(Crop("blueberry" , 6));
        }
    }
    void Farm::waterParsnips(int cropsToBeWatered, int energy) {
        /* int count = 0;
        for (unsigned int i = 0; i < starfruits.size(); i++) {
            if (!starfruits[i].getWaterStatus()) {
                count++;
            }
        } */

        if (cropsToBeWatered*2 <= energy) {
            for (unsigned int i = 0; i < parsnips.size(); i++) {
                if (!parsnips[i].getWaterStatus()) {
                    parsnips[i].water();
                }
            }
            std::cout << cropsToBeWatered << " Parsnips watered." << std::endl; 
        }
    }
    void Farm::waterStarfruits(int cropsToBeWatered, int energy) {
        /* int count = 0;
        for (unsigned int i = 0; i < starfruits.size(); i++) {
            if (!starfruits[i].getWaterStatus()) {
                count++;
            }
        } */

        if (cropsToBeWatered*2 <= energy) {
            for (unsigned int i = 0; i < starfruits.size(); i++) {
                if (!starfruits[i].getWaterStatus()) {
                    starfruits[i].water();
                }
            }
            std::cout << cropsToBeWatered << " Starfruits watered." << std::endl; 
        }
    }
    void Farm::waterBlueberries(int cropsToBeWatered, int energy) {
        /* int count = 0;
        for (unsigned int i = 0; i < starfruits.size(); i++) {
            if (!starfruits[i].getWaterStatus()) {
                count++;
            }
        } */

        if (cropsToBeWatered*2 <= energy) {
            for (unsigned int i = 0; i < blueberries.size(); i++) {
                if (!blueberries[i].getWaterStatus()) {
                    blueberries[i].water();
                }
            }
            std::cout << cropsToBeWatered << " Blueberry bushes watered." << std::endl; 
        }
    }

    int Farm::getHowManyParsnipsPlanted() {
        return parsnips.size();
    }
    int Farm::getHowManyStarfruitsPlanted() {
        return starfruits.size();
    }
    int Farm::getHowManyBlueberriesPlanted() {
        return blueberries.size();
    }

    int Farm::getHowManyParsnipsUnwatered() {
        int count = 0;
        for (unsigned int i = 0; i < parsnips.size(); i++) {
            if (!parsnips[i].getWaterStatus()) {
                count++;
            }
        }

        return count;
    }
    int Farm::getHowManyStarfruitsUnwatered() {
        int count = 0;
        for (unsigned int i = 0; i < starfruits.size(); i++) {
            if (!starfruits[i].getWaterStatus()) {
                count++;
            }
        }

        return count;
    }
    int Farm::getHowManyBlueberriesUnwatered() {
        int count = 0;
        for (unsigned int i = 0; i < blueberries.size(); i++) {
            if (!blueberries[i].getWaterStatus()) {
                count++;
            }
        }

        return count;
    }
