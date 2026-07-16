#include <string>
#include <vector>
#include <iostream>
#include "Farm.h"
#include "Crop.h"
#include "Item.h"
#include "Validation.h"

using namespace std;

Farm::Farm(std::string n, std::vector<Villager> people, int l) : Location(n, people, l) {
}


void Farm::plant(int parsnipSeeds, int starfuitSeeds, int blueberrySeeds) {
    // Plants by creating new crops and pushing back in the vector
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



void Farm::waterCrops(vector<Crop> crops,string name) {
    int waterCount;
    cout << "How many do you want to water? ";
    waterCount = promptInt(0,1000);
    if ((thePlayer.getEnergy() - 2*waterCount) < 0) {
        cout << "You don't have enough energy to do that" << endl;
    } 
    else {
        int count = 0;
        for (unsigned int i = 0; i < crops.size(); i++) {
            // Searches through the vector if a crop is unwatered than water it
            if (!crops[i].getWaterStatus()) {
                crops[i].water();
                count++;
                // If the amount of crops watered reaches how many the player wants then stop
                if (count == waterCount) {
                    thePlayer.setEnergy(thePlayer.getEnergy() - 2*count);
                    break;
                }
                // If the amount of crops the player wants watered is larger than the actual amount waterable then stop
                else if (i == (crops.size() - 1) ){
                    thePlayer.setEnergy(thePlayer.getEnergy() - 2*count);
                    break;
                }
            }
        }
        // Reassigns the crop vector we passed in to the corresponding actual vector of the farm
        if(name == "parsnips") {
            parsnips = crops;
        }
        else if(name == "starfruits") {
            starfruits = crops;
        }
        else if (name == "blueberries") {
            blueberries = crops;
        }
        
        cout << "You watered " << count << " " << name << "." << endl;    
    }
}


int Farm::getPlanted(std::vector<Crop> crops) {
    return crops.size();
}

int Farm::getUnwatered(std::vector<Crop> crops) {
    int count = 0;
    for (unsigned int i = 0; i < crops.size(); i++) {
        if (!crops[i].getWaterStatus()) {
            count++;
        }
    }

    return count;
}

int Farm::getHarvestable(std::vector<Crop> crops) {
    int count = 0;
    for (unsigned int i = 0; i < crops.size(); i++) {
        if (crops[i].getIfHarvestable()) {
            count++;
        }
    }
    return count;
}


bool Farm::farmTerminal(Player p, Item inventory[], Quest playerQuests[], int bundleTracker[]) {
// Overview of what can be done on the farm
thePlayer = p;
// If a day has passed outside the farm run what would happen if a day happened on the farm
if (thePlayer.getIfDayPassed()) {
    newDay();
}
while(true) {
    int choice;
    // Bundle tracker info seeing if the player has grown enough of certain crops
    if (getHarvestable(blueberries) >= 2) {
        if (bundleTracker[0] <= 3) {
            bundleTracker[0] = 4;
        }
    }

    if (getHarvestable(parsnips) >= 10) {
        if (bundleTracker[1] <= 3) {
            bundleTracker[1] = 4;
        }
    }

    if (getHarvestable(starfruits) >= 1) {
        if (bundleTracker[2] <= 3) {
            bundleTracker[2] = 4;
        }
    }

    cout << endl << endl;
    cout << "Day: " << thePlayer.getDay() << " Time: " << thePlayer.getTime() << endl;
    cout << "What would you like to do next? " << endl;
    // First menu
    cout << "===========================" << endl;
    cout << "1. Leave the " << getName() << endl;
    cout << "2. Tend to the farm" << endl;
    cout << "3. Check inventory" << endl;
    cout << "4. Check quests" << endl;
    cout << "5. Check map" << endl;
    cout << "6. Sleep" << endl;
    cout << "0. Exit the game" << endl;
    cout << "===========================" << endl;
    choice = promptInt(0,6);
    //Choice for first menu
    switch(choice) {

        case 1: {
            cout << "Leaving the farm! Going to town." << endl;
            thePlayer.setLocation("Town");
            // Time tracker
            if (thePlayer.setTime()) {
                cout << "It got too late, you passed out" << endl;
                thePlayer.newDayOutside();
                return true;
            }
            return true;
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
                cout << "Day: " << thePlayer.getDay() << " Time: " << thePlayer.getTime() << endl;
                cout << "You have " << p.getEnergy() << " energy." << endl;
                for (int i = 0; i < 10; i++) {
                    if (inventory[i].getSeed()) {
                        cout << "You have " << inventory[i].getAmount() << " " << inventory[i].getName() << endl;
                    }
                }
                cout << "===========================" << endl;
                cout << "You have " << getPlanted(parsnips) << " parsnips planted and " << getUnwatered(parsnips) << " unwatered. " << getHarvestable(parsnips) << " are harvestable." << endl;
                cout << "You have " << getPlanted(starfruits) << " starfruit planted and " << getUnwatered(starfruits) << " unwatered. " << getHarvestable(starfruits) << " are harvestable." << endl;
                cout << "You have " << getPlanted(blueberries) << " blueberry bushes planted and " << getUnwatered(blueberries) << " unwatered. " << getHarvestable(blueberries) << " are harvestable." << endl;
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
                choice2 = promptInt(1,10);
                //choice for second menu
                    switch (choice2) {
                        case 1: {
                            bool found = false;
                            int cropCount;
                            cout << "How many do you want to plant? ";
                            cropCount = promptInt(0,1000);
                            // Checks to see if there's enough seeds
                            for (int i = 0; i < 10; i++) {
                                if (inventory[i].getName() == "Parsnip seeds") {
                                    found = true;
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
                            if (!found) {
                                cout << "You don't have any parsnip seeds" << endl;
                            }
                            
                            if (getPlanted(parsnips) >= 10) {
                                if (bundleTracker[1] <= 2) {
                                    bundleTracker[1] = 3;
                                }
                            }
                            if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 2: {
                            waterCrops(parsnips,"parsnips");
                            if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 3: {
                            harvestCrops(parsnips, inventory, "Parsnip(s)" , "The humblest of crops");
                            if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 4: {
                            bool found = false;
                            int cropCount;
                            cout << "How many do you want to plant? ";
                            cropCount = promptInt(0,1000);
                            for (int i = 0; i < 10; i++) {
                                if (inventory[i].getName() ==  "Starfruit seeds") {
                                    found = true;
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
                            if (!found) {
                                cout << "You don't have any starfruit seeds" << endl;
                            }
                            if (getPlanted(starfruits) >= 1) {
                                if (bundleTracker[2] <= 2) {
                                    bundleTracker[2] = 3;
                                }
                            }
                            if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 5: {
                        waterCrops(starfruits,"starfruits");
                        if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                        }
                        break;
                        }

                        case 6: {
                            harvestCrops(starfruits, inventory, "Starfruit(s)" , "Truly luxurious fruit with a slight tangy flavor");
                            if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                            }
                            break;
                        }
                        case 7: {
                            bool found = false;
                            int cropCount;
                            cout << "How many do you want to plant? ";
                            cropCount = promptInt(0,1000);
                            for (int i = 0; i < 10; i++) {
                                if (inventory[i].getName() == "Blueberry seeds") {
                                    found = true;
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
                            if (!found) {
                                cout << "You don't have any blueberry seeds" << endl;
                            }
                            if (getPlanted(blueberries) >= 2) {
                                if (bundleTracker[0] <= 2) {
                                    bundleTracker[0] = 3;
                                }
                            }
                            if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 8: {
                            waterCrops(blueberries,"blueberries");
                            if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                            }
                            break;
                        }
                        case 9: {
                            harvestCrops(blueberries, inventory, "Blueberry(s)" , "Grows so that one plant can produce fruit mutiple times");
                            if (thePlayer.setTime()) {
                                cout << "It got too late, you passed out" << endl;
                                newDay();
                                return true;
                            }
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
                cout << inventory[i].getAmount() << " " << inventory[i].getName() << endl;
                }
            }
            if (thePlayer.setTime()) {
                cout << "It got too late, you passed out" << endl;
                newDay();
                return true;
            }
            if (thePlayer.setTime()) {
                cout << "It got too late, you passed out" << endl;
                newDay();
                return true;
            }
            break;
        }

        case 4: {
                bool hasQuests = false;
                cout << "Your bundle quests are: " << endl;
                for (int i = 0; i < 5; i++) {
                    if (playerQuests[i].getIfActive()) {
                        hasQuests = true;
                        cout << playerQuests[i].getName() << ": " << playerQuests[i].getDescription() << "." << endl;
                    }
                }
                hasQuests = false;
                cout << "Your other quests are: " << endl;
                for (int i = 5; i < 10; i++) {
                    if (playerQuests[i].getIfActive()) {
                        hasQuests = true;
                        cout << playerQuests[i].getName() << ": " << playerQuests[i].getDescription() <<  ". The reward is " << playerQuests[i].getReward().getName()  << "." << endl;
                    }
                }
                if (!hasQuests) {
                    cout << "You have no other quests active currently" << endl;
                }
                if (thePlayer.setTime()) {
                cout << "It got too late, you passed out" << endl;
                newDay();
                return true;
                }
                break;
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
            if (thePlayer.setTime()) {
                cout << "It got too late, you passed out" << endl;
                newDay();
                return true;
            }
            break;
        }

        case 6: {
            newDay();
            return true;
            break;
        }

        
        case 0: {
            return false;
        }
        default: {
        }
    }
}
}

        

void Farm::harvestCrops(std::vector<Crop> crops, Item inventory[10], std::string name,std::string description) {
    int harvestCount = 0;
    bool spaceFound = false;
    int howManyHarvest;
    cout << "How many do you want to harvest? ";
    howManyHarvest = promptInt(0,1000);
    // Does not immediateley increment i
    for (unsigned int i = 0; i < crops.size();) {
        // Searches through the vector to see which crops are harvestable
        if (crops[i].getIfHarvestable()) {
            harvestCount++;
            // If it's harvestable remove it from the vector
            crops.erase(crops.begin() + i);
            // See if enough are harvested
            if (harvestCount == howManyHarvest){
                break;
            }
            // Do not increase i, this prevents the issue where only every other harvestable crop is harvested
        }
        else {
            i++;
        }
    }

    if(name == "Parsnip(s)") {
            parsnips = crops;
        }
        else if(name == "Starfruit(s)") {
            starfruits = crops;
        }
        else if (name == "Blueberry(s)") {
            blueberries = crops;
        }

    // Adds the harvested items to inventory, for bluberries 5 times the amount harvested is added
    // Sees if the item is already in the player's inventory if so it just adds
    for (unsigned int i = 0; i < 10; i++) {
        if (inventory[i].getName() == name) {
        spaceFound = true;
        if (name == "Blueberry(s)") {
            inventory[i].setAmount(harvestCount * 5);
        }
        else {
        inventory[i].setAmount(harvestCount);
        }
        break;
        }
    }
    // If the item isn't already there it must make a new item
    for (unsigned int i = 0; i < 10; i++) {
        if (spaceFound == true) {break;}
        if (inventory[i].getAmount() == 0) {
            spaceFound = true;
            if (name == "Blueberry(s)") {
            inventory[i] = Item (description,harvestCount*5, name,0);
            }
            else {
            inventory[i] = Item (description,harvestCount, name,0);
            }
            break;
        }
    }

    if (spaceFound == false) {
        cout << "Your unable to harvest as you don't have any inventory space" << endl;
    }
    else {
        cout << "You harvested " << harvestCount << " " << name << "." << endl;
    }
}

void Farm::newDay() {
    string actualWeather;
    // Adds to the players day
    thePlayer.newDay();
    // Displays what the weather is with words
    if (thePlayer.getWeather() == 1) {
        actualWeather = "sunny";
    }
    else if(thePlayer.getWeather() == 2) {
        actualWeather = "rainy";
    }
    else if (thePlayer.getWeather() == 3) {
        actualWeather = "stormy";
    }
    else {
        actualWeather = "==============";
    }

    // Each crop goes through nextDay()
    for (unsigned int i = 0; i < parsnips.size(); i++) {
        parsnips[i].nextDay();
    }

    for (unsigned int i = 0; i < starfruits.size(); i++) {
        starfruits[i].nextDay();
    }

    for (unsigned int i = 0; i < blueberries.size(); i++) {
        blueberries[i].nextDay();
    }
    cout << endl;
    cout << "===========================" << endl;
    cout << "It's a new day on the farm." << endl;
    cout << "The weather is " << actualWeather << "." << endl;
    cout << "===========================" << endl;

    // If it's stormy or rainy water all crops
    if (thePlayer.getWeather() == 2 || thePlayer.getWeather() == 3) {
        for (unsigned int i = 0; i < parsnips.size(); i++) {
                parsnips[i].water();
        }
        for (unsigned int i = 0; i < starfruits.size(); i++) {
                starfruits[i].water();
        }
        for (unsigned int i = 0; i < blueberries.size(); i++) {
                blueberries[i].water();
        }
    }
    // If a day has passed outside the farm then this function would be called
    // Now set it that no day has passed outside
    thePlayer.setIfDay();
}







