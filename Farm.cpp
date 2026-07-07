#include <string>
#include <vector>
#include <iostream>
#include "Farm.h"
#include "Crop.h"

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
    void Farm::waterStarfruits(int cropsToBeWatered) {

        if ((thePlayer.getEnergy() - 2*cropsToBeWatered) < 0) {
            cout << "You don't have enough energy to do that" << endl;
        } 
        else {
            int count = 0;
            for (unsigned int i = 0; i < starfruits.size(); i++) {
                if (!starfruits[i].getWaterStatus()) {
                    starfruits[i].water();
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
            
            cout << "You watered " << count << " starfruits." << endl;
        
        }
    }
    void Farm::waterBlueberries(int cropsToBeWatered) {

        if ((thePlayer.getEnergy() - 2*cropsToBeWatered) < 0) {
            cout << "You don't have enough energy to do that" << endl;
        } 
        else {
            int count = 0;
            for (unsigned int i = 0; i < blueberries.size(); i++) {
                if (!blueberries[i].getWaterStatus()) {
                    blueberries[i].water();
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
            
            cout << "You watered " << count << " blueberries." << endl;
        
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

    bool Farm::farmTerminal(Player p, Item inventory[]) {
    // Overview of what can be done on the farm
    thePlayer = p;
    while(true) {
        int choice;
        cout << "What would you like to do next? " << endl;
        cout << "1. Leave the " << getName() << endl;
        cout << "2. Tend to the farm" << endl;
        cout << "3. Check inventory" << endl;
        cout << "4. Check quests" << endl;
        cout << "5. Sleep" << endl;
        cout << "-1. Exit the game" << endl;
        cin >> choice;

        //Choice for first menu
        switch(choice) {

            case 1: {
                cout << "Leaving the farm!" << endl;
                break;
            }

            case 2: {
                // Overview of what tending can be done
                int choice2;
                bool exit = true;
                while(exit) {
                    p = thePlayer;
                    int count = 1;
                    cout << endl;
                    cout << "You have " << p.getEnergy() << " energy." << endl;
                    for (int i = 0; i < 10; i++) {
                        if (inventory[i].getSeed()) {
                            cout << "You have " << inventory[i].getAmount() << " " << inventory[i].getName() << endl;
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
                            cout << count << ". Plant " << inventory[i].getName() << endl;
                            count++;
                            cout << count << ". Water " << inventory[i].getName() << "(s)." << endl;
                            count++; 
                        }
                    }
                    cout << "7. Exit" << endl;
                    cin >> choice2;
                    //choice for second menu
                        switch (choice2) {
                            case 1: {
                                int cropCount;
                                cout << "How many do you want to plant? ";
                                cin >> cropCount;
                                for (int i = 0; i < 10; i++) {
                                    if (inventory[i].getName() == "Parsnip seeds") {

                                        if (inventory[i].getAmount() < cropCount) {
                                            cout << "You don't have enough parsnip seeds." << endl;
                                        }
                                        else {
                                            plant(cropCount, 0, 0);
                                            inventory[i].setAmount(-cropCount);
                                        }

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
                                break;
                            }

                            case 3: {
                                int cropCount;
                                cout << "How many do you want to plant? ";
                                cin >> cropCount;
                                for (int i = 0; i < 10; i++) {
                                    if (inventory[i].getName() == "Starfruit seeds") {

                                        if (inventory[i].getAmount() < cropCount) {
                                            cout << "You don't have enough starfruit seeds." << endl;
                                        }
                                        else {
                                            plant(0, cropCount, 0);
                                            inventory[i].setAmount(-cropCount);
                                        }

                                        break;
                                    }
                                }
                                break;
                            }

                            case 4: {
                                int waterCount;
                                cout << "How many do you want to water? ";
                                cin >> waterCount;
                                waterStarfruits(waterCount);
                                break;
                            }
                            case 5: {
                                int cropCount;
                                cout << "How many do you want to plant? ";
                                cin >> cropCount;
                                for (int i = 0; i < 10; i++) {
                                    if (inventory[i].getName() == "Blueberry seeds") {

                                        if (inventory[i].getAmount() < cropCount) {
                                            cout << "You don't have enough blueberry seeds." << endl;
                                        }
                                        else {
                                            plant(0, 0, cropCount);
                                            inventory[i].setAmount(-cropCount);
                                        }

                                        break;
                                    }
                                }
                                break;
                            }

                            case 6: {
                                int waterCount;
                                cout << "How many do you want to water? ";
                                cin >> waterCount;
                                waterBlueberries(waterCount);
                                break;
                            }

                            case 7: {
                                exit = false;
                                break;
                            }
                        }
                }
                break;
            }

            case 3: {
                cout << "The items in your inventory are:" << endl;
                for (int i = 0; i < 10; i++) {
                    cout << inventory[i].getAmount() << " " << inventory[i].getName() << endl;
                }
            }

            case 4: {

            }

            case 5: {
                thePlayer.newDay();
                for (unsigned int i = 0; i < parsnips.size(); i++) {
                    parsnips[i].nextDay();
                }
                for (unsigned int i = 0; i < starfruits.size(); i++) {
                    starfruits[i].nextDay();
                }
                for (unsigned int i = 0; i < blueberries.size(); i++) {
                    blueberries[i].nextDay();
                }
                return true;
            }
 
            
            case -1: {
                return false;
            }
            default: {
            }
        }
    }
}

Player Farm::getThePlayer() {
    return thePlayer;
}

void Farm::harvestParsnips(int inventory[10], int howManyHarvest) {
    int harvestCount = 0;
    for (unsigned int i = 0; i < parsnips.size(); i++ ) {
        if (parsnips[i].getIfHarvestable()) {
            harvestCount++;
        }

        if (harvestCount == howManyHarvest){
            break;
        }
    }


}

