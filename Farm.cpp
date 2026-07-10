#include <string>
#include <vector>
#include <iostream>
#include "Farm.h"
#include "Crop.h"
#include "Item.h"

using namespace std;

Farm::Farm(std::string n, std::vector<Villager> people) : Location(n, people) {
}

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



void Farm::waterCrops(vector<Crop> crops,string name) {
    int waterCount;
    cout << "How many do you want to water? ";
    cin >> waterCount;
    if ((thePlayer.getEnergy() - 2*waterCount) < 0) {
        cout << "You don't have enough energy to do that" << endl;
    } 
    else {
        int count = 0;
        for (unsigned int i = 0; i < crops.size(); i++) {
            if (!crops[i].getWaterStatus()) {
                crops[i].water();
                count++;
                if (count == waterCount) {
                    thePlayer.setEnergy(thePlayer.getEnergy() - 2*count);
                    break;
                }
                else if (i == (crops.size() - 1) ){
                    thePlayer.setEnergy(thePlayer.getEnergy() - 2*count);
                    break;
                }
            }
        }

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


bool Farm::farmTerminal(Player p, Item inventory[]) {
// Overview of what can be done on the farm
thePlayer = p;
if (thePlayer.getIfDayPassed()) {
    newDay();
}
while(true) {
    int choice;

    cout << endl << endl;
    cout << "Day: " << thePlayer.getDay() << " Time: " << thePlayer.getTime() << endl;
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
    //Choice for first menu
    switch(choice) {

        case 1: {
            cout << "Leaving the farm! Going to town." << endl;
            thePlayer.setLocation("Town");
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
                            if (thePlayer.setTime()) {
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 2: {
                            waterCrops(parsnips,"parsnips");
                            if (thePlayer.setTime()) {
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 3: {
                            harvestCrops(parsnips, inventory, "Parsnip(s)" , "The humblest of crops");
                            if (thePlayer.setTime()) {
                                newDay();
                                return true;
                            }
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
                            if (thePlayer.setTime()) {
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 5: {
                        waterCrops(starfruits,"starfruits");
                        if (thePlayer.setTime()) {
                            newDay();
                            return true;
                        }
                        break;
                        }

                        case 6: {
                            harvestCrops(starfruits, inventory, "Starfruit(s)" , "Truly luxurious fruit with a slight tangy flavor");
                            if (thePlayer.setTime()) {
                                newDay();
                                return true;
                            }
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
                            if (thePlayer.setTime()) {
                                newDay();
                                return true;
                            }
                            break;
                        }

                        case 8: {
                            waterCrops(blueberries,"blueberries");
                            if (thePlayer.setTime()) {
                                newDay();
                                return true;
                            }
                            break;
                        }
                        case 9: {
                            harvestCrops(blueberries, inventory, "Blueberry(s)" , "Grows so that one plant can produce fruit mutiple times");
                            if (thePlayer.setTime()) {
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
                newDay();
                return true;
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
            if (thePlayer.setTime()) {
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

        

void Farm::harvestCrops(std::vector<Crop> crops, Item inventory[10], std::string name,std::string description) {
    int harvestCount = 0;
    bool spaceFound = false;
    int howManyHarvest;
    cout << "How many do you want to harvest? ";
    cin >> howManyHarvest;
    for (unsigned int i = 0; i < crops.size();) {
        if (crops[i].getIfHarvestable()) {
            harvestCount++;
            crops.erase(crops.begin() + i);
        

        if (harvestCount == howManyHarvest){
            break;
        }
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

    for (unsigned int i = 0; i < 10; i++) {
        if (inventory[i].getName() == name) {
        spaceFound = true;
        inventory[i].setAmount(harvestCount);
        break;
        }
    }

    for (unsigned int i = 0; i < 10; i++) {
        if (spaceFound == true) {break;}
        if (inventory[i].getAmount() == 0) {
            spaceFound = true;
            inventory[i] = Item (description,harvestCount, name,0);
            break;
        }
    }

    if (spaceFound == false) {
        cout << "Your unable to harvest as you don't have any inventory space" << endl;
    }
}

void Farm::newDay() {
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
cout << endl;
cout << "===========================" << endl;
cout << "It's a new day on the farm." << endl;
cout << "===========================" << endl;

}







