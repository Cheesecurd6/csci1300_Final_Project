#include <string>
#include <vector>
#include <iostream>
#include "Farm.h"
#include "Crop.h"
#include "Item.h"

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
                    else if (i == (starfruits.size() - 1) ){
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
                    else if (i == (blueberries.size() - 1) ){
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

    int Farm::getHowManyParsnipsHarvestable() {
        int count = 0;
        for (unsigned int i = 0; i < parsnips.size(); i++) {
            if (parsnips[i].getIfHarvestable()) {
                count++;
            }
        }
        return count;
    }

    int Farm::getHowManyStarfruitsHarvestable() {
        int count = 0;
        for (unsigned int i = 0; i < starfruits.size(); i++) {
            if (starfruits[i].getIfHarvestable()) {
                count++;
            }
        }
        return count;
    }

    int Farm::getHowManyBlueberriesHarvestable() {
        int count = 0;
        for (unsigned int i = 0; i < blueberries.size(); i++) {
            if (blueberries[i].getIfHarvestable()) {
                count++;
            }
        }
        return count;
    }

    bool Farm::farmTerminal(Player p, Item inventory[]) {
    // Overview of what can be done on the farm
    thePlayer = p;
    day = thePlayer.getDay();
    time = thePlayer.getTime();
    while(true) {
        int choice;
        cout << "What would you like to do next? " << endl;

        cout << "===========================" << endl;
        cout << "1. Leave the " << getName() << endl;
        cout << "2. Tend to the farm" << endl;
        cout << "3. Check inventory" << endl;
        cout << "4. Check quests" << endl;
        cout << "5. Check map" << endl;
        cout << "6. Sleep" << endl;
        cout << "-1. Exit the game" << endl;
        cout << "===========================" << endl;
        cin >> choice;
        if (thePlayer.setTime()) {
            return true;
        }
        //Choice for first menu
        switch(choice) {

            case 1: {
                cout << "Leaving the farm! Going to town." << endl;
                break;
            }

            case 2: {
                // Overview of what tending can be done
                int choice2;
                bool exit = true;
                while(exit) {
                    p = thePlayer;
                    cout << endl;
                    cout << "===========================" << endl;
                    cout << "You have " << p.getEnergy() << " energy." << endl;
                    for (int i = 0; i < 10; i++) {
                        if (inventory[i].getSeed()) {
                            cout << "You have " << inventory[i].getAmount() << " " << inventory[i].getName() << endl;
                        }
                    }
                    cout << "===========================" << endl;
                    cout << "You have " << getHowManyParsnipsPlanted() << " parsnips planted and " << getHowManyParsnipsUnwatered() << " unwatered. " << getHowManyParsnipsHarvestable() << " are harvestable." << endl;
                    cout << "You have " << getHowManyStarfruitsPlanted() << " starfruit planted and " << getHowManyStarfruitsUnwatered() << " unwatered. " << getHowManyStarfruitsHarvestable() << " are harvestable." << endl;
                    cout << "You have " << getHowManyBlueberriesPlanted() << " blueberry bushes planted and " << getHowManyBlueberriesUnwatered() << " unwatered. " << getHowManyBlueberriesHarvestable() << " are harvestable." << endl;
                    cout << "===========================" << endl;


                    cout << "Watering crops takes 2 energy" << endl;
                    cout << "What would you like to do?" << endl;
                    cout << "===========================" << endl;
                    cout << "1. Plant parsnip seeds" << endl;
                    cout << "2. Water parsnips" << endl;
                    cout << "3. Harvest parsnips" << endl;
                    cout << "4. Plant starfruit seeds" << endl;
                    cout << "5. Water starfruits" << endl;
                    cout << "6. Harvest starfruits" << endl;
                    cout << "7. Plant blueberry seeds" << endl;
                    cout << "8. Water blueberries" << endl;
                    cout << "9. Harvest blueberries" << endl;
                    cout << "10. Exit" << endl;
                    cout << "===========================" << endl;
                    cin >> choice2;
                    if (thePlayer.setTime()) {
                        return true;
                    }
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
                                int howManyHarvest;
                                cout << "How many do you want to harvest? ";
                                cin >> howManyHarvest;
                                harvestParsnips(inventory,howManyHarvest); 
                                break;
                            }

                            case 4: {
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

                            case 5: {
                                int waterCount;
                                cout << "How many do you want to water? ";
                                cin >> waterCount;
                                waterStarfruits(waterCount);
                                break;
                            }

                            case 6: {
                                int howManyHarvest;
                                cout << "How many do you want to harvest? ";
                                cin >> howManyHarvest;
                                harvestStarfruits(inventory,howManyHarvest); 
                                break;
                            }
                            case 7: {
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

                            case 8: {
                                int waterCount;
                                cout << "How many do you want to water? ";
                                cin >> waterCount;
                                waterBlueberries(waterCount);
                                break;
                            }
                            case 9: {
                                int howManyHarvest;
                                cout << "How many do you want to harvest? ";
                                cin >> howManyHarvest;
                                harvestBlueberries(inventory,howManyHarvest); 
                                break;
                            }

                            case 10: {
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
                    if (!(inventory[i].getAmount() == 0)) {
                    cout << i << endl;
                    cout << inventory[i].getAmount() << " " << inventory[i].getName() << endl;
                    }
                }
                break;
            }

            case 4: {

            }

            case 5: {
                cout << "                Mines" << endl;
                cout << "                  |" << endl;
                cout << "                  |" << endl;
                cout << "Farm ----------- Town ----------- Joja Mart" << endl;
                cout << "                  |" << endl;
                cout << "                  |" << endl;
                cout << "                Beach" << endl;

                cout << endl << "Currently at " << thePlayer.getLocation() << "." << endl;
                break;
            }

            case 6: {
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
                cout << "===========================" << endl;
                cout << "It's a new day on the farm." << endl;
                cout << "===========================" << endl;
                return true;
                break;
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

void Farm::harvestParsnips(Item inventory[10], int howManyHarvest) {
    int harvestCount = 0;
    bool spaceFound = false;
        for (unsigned int i = 0; i < parsnips.size();) {
            if (parsnips[i].getIfHarvestable()) {
                harvestCount++;
                parsnips.erase(parsnips.begin() + i);
            

            if (harvestCount == howManyHarvest){
                break;
            }
            }
            else {
                i++;
            }

        }
        for (unsigned int i = 0; i < 10; i++) {
           if (inventory[i].getName() == "Parsnip(s)" && !(inventory[i].getAmount() == 0)) {
            spaceFound = true;
            inventory[i] = Item ("The humblest of crops ",harvestCount,30, "Parsnip(s)",0);
            break;
            }
        }
        for (unsigned int i = 0; i < 10; i++) {
            if (spaceFound == true) {break;}
            if (inventory[i].getAmount() == 0) {
                spaceFound = true;
                inventory[i] = Item ("The humblest of crops  ",harvestCount,30, "Parsnip(s)",0);
                break;
            }
        }

        if (spaceFound == false) {
            cout << "Your unable to harvest you don't have any inventory space" << endl;
        }
}


    void Farm::harvestStarfruits(Item inventory[10], int howManyHarvest) {
    int harvestCount = 0;
        bool spaceFound = false;
        for (unsigned int i = 0; i < starfruits.size();) {
            if (starfruits[i].getIfHarvestable()) {
                harvestCount++;
                starfruits.erase(starfruits.begin() + i);
            

            if (harvestCount == howManyHarvest){
                break;
            }
            }
            else {
                i++;
            }

        }
        for (unsigned int i = 0; i < 10; i++) {
           if (inventory[i].getName() == "Starfruit(s)" && !(inventory[i].getAmount() == 0)) {
            spaceFound = true;
            inventory[i] = Item ("Truly luxurious fruit with a slight tangy flavor ",harvestCount,30, "Starfruit(s)",0);
            break;
            }
        }
        for (unsigned int i = 0; i < 10; i++) {
            if (spaceFound == true) {break;}
            if (inventory[i].getAmount() == 0) {
                spaceFound = true;
                inventory[i] = Item ("Truly luxurious fruit with a slight tangy flavor ",harvestCount,30, "Starfruit(s)",0);
                break;
            }
        }

        if (spaceFound == false) {
            cout << "Your unable to harvest you don't have any inventory space" << endl;
        }
    }

    void Farm::harvestBlueberries(Item inventory[10], int howManyHarvest) {
    int harvestCount = 0;
        bool spaceFound = false;
        for (unsigned int i = 0; i < blueberries.size();) {
            if (blueberries[i].getIfHarvestable()) {
                harvestCount++;
                blueberries.erase(blueberries.begin() + i);
            

            if (harvestCount == howManyHarvest){
                break;
            }
            }
            else {
                i++;
            }

        }
        for (unsigned int i = 0; i < 10; i++) {
           if (inventory[i].getName() == "Blueberry(s)" && !(inventory[i].getAmount() == 0)) {
            spaceFound = true;
            inventory[i] = Item ("Grows so that one plant can produce fruit mutiple times ",harvestCount,30, "Blueberry(s)",0);
            break;
            }
        }

        for (unsigned int i = 0; i < 10; i++) {
            if (spaceFound == true) {break;}
            if (inventory[i].getAmount() == 0) {
                spaceFound = true;
                inventory[i] = Item ("Grows so that one plant can produce fruit mutiple times ",harvestCount,30, "Blueberry(s)",0);
                break;
            }
        }

        if (spaceFound == false) {
            cout << "Your unable to harvest as you don't have any inventory space" << endl;
        }
    }





