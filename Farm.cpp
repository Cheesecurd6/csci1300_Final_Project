#include <string>
#include <vector>
#include <iostream>
#include "Farm.hpp"
#include "Crop.hpp"

using namespace std;

// Try/Catch statement with the input of how many crops watered.
    void Farm::plant(int parsnipSeeds, int starfuitSeeds, int blueberrySeeds) {
        for(int i = 0; i < parsnipSeeds; i++) {
            parsnips.push_back(Crop("parsnip" , 2, false));
        }

        for(int i = 0; i < starfuitSeeds; i++) {
            starfruits.push_back(Crop("starfruit" , 4, false));
        }

        for(int i = 0; i < blueberrySeeds; i++) {
            blueberries.push_back(Crop("blueberry" , 6, false));
        }
    }
    void Farm::waterParsnips(int cropsToBeWatered) {

        if ((thePlayer.getEnergy() - 2*cropsToBeWatered) < 0) {
            cout << "You don't have enough energy to do that" << endl;
        } 
        else {
            int count = 0;
            for (unsigned int i = 0; i < parsnips.size(); i++) {
                if (!parsnips[i].getWaterStatus()) {
                    parsnips[i].water();
                    count++;
                    if (count == cropsToBeWatered) {
                        thePlayer.setEnergy(thePlayer.getEnergy() - 2*count);
                        break;
                    }
                    else if (i == (parsnips.size() - 1) ){
                        thePlayer.setEnergy(thePlayer.getEnergy() - 2*count);
                        break;
                    }
                }
            }
            
            cout << "You watered " << count << " parsnips." << endl;
        
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
    void Farm::waterBlueberries(int cropsToBeWatered) {
        /* int count = 0;
        for (unsigned int i = 0; i < starfruits.size(); i++) {
            if (!starfruits[i].getWaterStatus()) {
                count++;
            }
        } */
        if ((thePlayer.getEnergy() - 2*cropsToBeWatered) < 0) {
            cout << "You don't have enough energy to do that" << endl;
        } 
        else {
            thePlayer.setEnergy(thePlayer.getEnergy() - 2*cropsToBeWatered);
            cout << "You watered " << cropsToBeWatered << " blueberries." << endl;
        }

        if (cropsToBeWatered*2 <= thePlayer.getEnergy()) {
            for (unsigned int i = 0; i < blueberries.size(); i++) {
                int count = 0;
                if (!blueberries[i].getWaterStatus()) {
                    blueberries[i].water();
                    count++;
                    if (count == cropsToBeWatered) {
                        break;
                    }
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

    void Farm::farmTerminal(Player p, Item inventory[]) {
    // Overview of what can be done on the farm
    thePlayer = p;
    while(true) {
        int choice;
        cout << "What would you like to do next? " << endl;
        cout << "1. Leave the " << getName() << endl;
        cout << "2. Tend to the farm" << endl;
        cout << "3. Sleep" << endl;
        cout << "4. Check inventory" << endl;
        cout << "5. Check quests" << endl;
        cout << "-1. Exit the game" << endl;
        cin >> choice;

        switch(choice) {

            case 1: {
                cout << "Leaving the farm!" << endl;
                break;
            }

            case 2: {
                // Overview of what tending can be done
                int choice2;
                while(true) {
                p = thePlayer;
                int count = 1;
                cout << endl;
                cout << "You have " << p.getEnergy() << " energy." << endl;
                for (int i = 0; i < 10; i++) {
                    if (inventory[i].getSeed()) {
                        cout << "You have " << inventory[i].getAmount() << " " << inventory[i].getName() << " seeds." << endl;
                    }
                }

                cout << "You have " << getHowManyParsnipsPlanted() << " parsnips planted and " << getHowManyParsnipsUnwatered() << " unwatered." << endl;
                cout << "You have " << getHowManyStarfruitsPlanted() << " starfruit planted and " << getHowManyStarfruitsUnwatered() << " unwatered." << endl;
                cout << "You have " << getHowManyBlueberriesPlanted() << " blueberry bushes planted and " << getHowManyBlueberriesUnwatered() << " unwatered." << endl;
                cout << endl;
                cout << "Watering crops takes 2 energy" << endl;
                cout << "What would you like to do?" << endl;

                for (int i = 0; i < 10; i++) {
                    if (inventory[i].getSeed()) {
                        cout << count << ". Plant " << inventory[i].getName() << " seeds." << endl;
                        count++;
                        cout << count << ". Water " << inventory[i].getName() << "(s)." << endl;
                        count++; 
                    }
                }
                cin >> choice2;
                    switch (choice2) {
                        case 1: {
                            int cropCount;
                            cout << "How many do you want to plant? ";
                            cin >> cropCount;
                            plant(cropCount,0,0);
                            for (int i = 0; i < 10; i++) {
                                if (inventory[i].getName() == "Parsnip") {
                                    inventory[i].setAmount(-count);
                                    break; 
                                }
                            }
                        break;
                        }

                        case 2: {
                            int waterCount;
                            cout << "How many do you want to water? ";
                            cin >> waterCount;
                            waterParsnips(waterCount);
                        }
                    }
                }
            break;
            }

            
            case -1: {
                return;
            }
            default: {

            }
        }
    }
}
