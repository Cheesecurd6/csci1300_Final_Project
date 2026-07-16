#include <string>
#include <vector>
#include <iostream>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "Town.h"
#include "Joja.h"
#include "Validation.h"

using namespace std;

Joja::Joja(std::string n, std::vector<Villager> people, int l) : Location(n,people,l){}

void Joja::buy(Item inventory[10], std::string name, std::string description, int price) {

    int amountBought;
    cout << name << " cost " << price << " gold." << endl;
    cout << "How many would you like to purchase? ";
    amountBought = promptInt(0,1000);

    if (amountBought * price <= thePlayer.getGold()) {
        bool spaceFound = false;
        for (unsigned int i = 0; i < 10; i++) {
            if (inventory[i].getName() == name && !(inventory[i].getAmount() == 0)) {
                spaceFound = true;
                inventory[i].setAmount(amountBought);
                thePlayer.setGold(-(amountBought * price));
                break;
                }
            }
        for (unsigned int i = 0; i < 10; i++) {
            if (spaceFound == true) {break;}
            if (inventory[i].getAmount() == 0) {
                spaceFound = true;
                inventory[i] = Item (description,amountBought, name ,1);
                thePlayer.setGold(-(amountBought * price));
                break;
            }
        }
        if (spaceFound == false) {
            cout << "Your unable to buy, you don't have any inventory space" << endl;
        }
        else {
            thePlayer.setJoja();
        }
    } 
    else {
        cout << "You don't have enough gold to buy that many." << endl;
    }
        
}

bool Joja::addItem(Item inventory[10], Item questReward) {

    bool spaceFound = false;
    for (unsigned int i = 0; i < 10; i++) {
            if (inventory[i].getName() == questReward.getName()) {
            spaceFound = true;
            inventory[i].setAmount(questReward.getAmount());
            break;
            }
        }

    for (unsigned int i = 0; i < 10; i++) {
        if (spaceFound == true) {break;}
        if (inventory[i].getAmount() == 0) {
            spaceFound = true;
            inventory[i] = questReward;
            break;
        }
    }

    if (spaceFound == false) {
        return false;
    }
    else {
        return true;
    }
}

bool Joja::searchPlayerInventory(Item questItem, Item inventory[10]) {
    for (int i = 0; i < 10; i++) {
        if (inventory[i].getName() == questItem.getName()) {
            if(inventory[i].getAmount() >= questItem.getAmount()) {
                inventory[i].setAmount(-questItem.getAmount());
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}
void Joja::questCheck(int p, Quest playerQuests[10], Item inventory[10]) {
        for (int i = 0; i < 10; i++) {
        if (playerQuests[i].getName() == getPeople()[p].getQuest()) {
            if (playerQuests[i].getIfActive()) {
                if (searchPlayerInventory(playerQuests[i].getRequirement(),inventory)) {
                    cout << "===========================" << endl;
                    cout << "\"Oh I see you have the items I asked for thank you for this. Now for your reward.\"" << endl;
                    if (addItem(inventory,playerQuests[i].getReward())) {
                        cout << "\"Here you go, it's " << playerQuests[i].getReward().getName() << ".\"" << endl;
                        cout << "===========================" << endl;
                        playerQuests[i].setIfActive(0);
                        playerQuests[i].setIfCompleted(1);
                    }
                    else {
                        cout << "\"Sorry it looks like you don't have enough inventory space, come back when you do have the requisite space.\"" << endl;
                        cout << "===========================" << endl;
                    }
                }
            }
        } 
    }
}

bool Joja::jojaTerminal(Player p, Item inventory[], Quest playerQuests[], int bundleTracker[]) {
    thePlayer = p;
    cout << bundleTracker[1] << endl;
    while(true) {
        int choice;
        cout << endl << endl;
        cout << "Day: " << thePlayer.getDay() << " Time: " << thePlayer.getTime() << endl;
        cout << "What would you like to do next? " << endl;
        //First menu
        cout << "===========================" << endl;
        cout << "1. Leave the " << getName() << endl;
        cout << "2. Talk to Morris" << endl;
        cout << "3. Check inventory" << endl;
        cout << "4. Check quests" << endl;
        cout << "5. Check map" << endl;
        cout << "6. Buy items" << endl;
        cout << "0. Exit the game" << endl;
        cout << "===========================" << endl;
        choice = promptInt(0,6);
        if (thePlayer.setTime()) {
            cout << "It got too late, you passed out" << endl;
            thePlayer.newDayOutside();
            return true;
        }
        switch(choice) {
            case 1: {
                cout << "Leaving the Joja mart! Going to town." << endl;
                thePlayer.setLocation("Town");
                return true;
                break;
            }
            case 2: {
                int choice3;
                cout << "===========================" << endl;
                cout << "\"Oh hello there " << thePlayer.getName() << "welcome to Joja mart, I'm " << getPeople()[0].getName() << " " << getPeople()[0].getDescription() << ", what can I do for you?\"" << endl;
                cout << "===========================" << endl;

                cout << "===========================" << endl;
                cout << "1. \"What can I buy here?\"" << endl;
                cout << "2. \"Do you ever feel bad that your corporation's greed is destroying this town?\"" << endl;
                cout << "3. \"What'll happen to the community center if I buy items from you?\"" << endl;
                cout << "===========================" << endl;
                choice3 = promptInt(0,3);
                switch(choice3) {
                    case 1: {
                        cout << "\"Young man Joja has it all, blueberries, truffle oil, crystal fruit, octopus, even lab-grown diamonds. I hear those are the things your looking for. If you need help finding anything I'm happy to help. We also sell seeds, at much more affordable prices than that swindler Pierre. Just remember join us, thrive.\"" << endl;
                        break;
                    }
                    case 2: {
                        cout << "\"No.\"" << endl;
                        break;
                    }
                    case 3: {
                        cout << "\"Nothing will happen immediateley, but well you hold a certain sway in this town. Buying from us is an endorsement, and an endorsement from you is worth more than gold. People will see the Joja side of things eventually. They are already starting too. We'll help you build the community center, but that won't drive us out of town.\"" << endl;
                        break;
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
                break;
            }
            case 6: {
                int choice2;
                bool exit = true;
                while(exit) {
                    // Store menu
                    cout << endl;
                    cout << "===========================" << endl;
                    cout << "Day: " << thePlayer.getDay() << " Time: " << thePlayer.getTime() << endl;
                    cout << "You currently have " << thePlayer.getGold() << " gold" << endl;
                    cout << "===========================" << endl;
                    cout << "What do you want to buy/sell?" << endl;
                    cout << "===========================" << endl;
                    cout << "1. Buy parsnip seeds" << endl;
                    cout << "2. Buy starfruit seeds" << endl;
                    cout << "3. Buy blueberry seeds" << endl;
                    cout << "4. Buy blueberries" << endl;
                    cout << "5. Buy truffle oil" << endl;
                    cout << "6. Buy crystal fruit" << endl;
                    cout << "7. Buy octopus" << endl;
                    cout << "8. Buy diamonds" << endl;
                    cout << "9. Exit" << endl;
                    cout << "===========================" << endl;
                    choice2 = promptInt(1,9);

                    if (thePlayer.setTime()) {
                        cout << "It got too late, you passed out" << endl;
                        thePlayer.newDayOutside();
                        return true;
                    }

                    switch(choice2) {
                        case 1: {
                            buy(inventory,"Parsnip seeds", "The humblest of crops",15);
                            break;
                        }
                        case 2: {
                            buy(inventory,"Starfruit seeds", "Truly luxurious fruit with a slight tangy flavor",40);
                            break;
                        }

                        case 3: {
                            buy(inventory,"Blueberry seeds", "Grows so that one plant can produce mutiple fruits when harvested",25);
                            break;
                        }

                        case 4: {
                            buy(inventory,"Blueberry(s)", "Grows so that one plant can produce mutiple fruits when harvested",25);
                            break;
                        }

                        case 5: {
                            buy(inventory, "Truffle Oil","Truffle oil smells funky but can be used to cook amazing dishes", 50);
                            break;
                        }
                        case 6: {
                            buy(inventory,"Crystal Fruit","A prize fruit, often only foraged during the winter or collected from the coldest depths of the mines",80 );
                            break;
                        }
                        case 7: {
                            buy(inventory, "Octopus", "A mysterious creature from the depths of the ocean; delicious with a little lemona and salt", 500);
                            break;
                        }
                        case 8: {
                            buy(inventory,"Diamond(s)","Shiny shiny", 1000);
                            break;
                        }
                        case 9: {
                            exit = false;
                            break;
                        }
                    }
                }
                break;
            }
            case 0: {
                return false;
                break;
            }
        }
    }
}
