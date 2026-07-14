#include <string>
#include <vector>
#include <iostream>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "Town.h"
using namespace std;

Town::Town(std::string n, std::vector<Villager> people, int l) : Location(n, people,l) {}

Player Town::getThePlayer() {
    return thePlayer;
}

bool Town::townTerminal(Player p, Item inventory[10], Quest playerQuests[10], int bundleTracker[]) {
    thePlayer = p;

    while(true) {
        int choice;

        cout << endl << endl;
        cout << "Day: " << thePlayer.getDay() << " Time: " << thePlayer.getTime() << endl;
        cout << "What would you like to do next? " << endl;
        //First menu
        cout << "===========================" << endl;
        cout << "1. Leave the " << getName() << endl;
        cout << "2. Talk to Villagers" << endl;
        cout << "3. Check inventory" << endl;
        cout << "4. Check quests" << endl;
        cout << "5. Check map" << endl;
        cout << "6. Sell/Buy items at the store" << endl;
        cout << "7. Check the bundle" << endl;
        cout << "-1. Exit the game" << endl;
        cout << "===========================" << endl;
        cin >> choice;
        if (thePlayer.setTime()) {
            cout << "It got too late, you passed out" << endl;
            thePlayer.newDayOutside();
            return true;
        }
       
        switch(choice) {
            case 1: {
                int choice2;
                cout << "Where do you want to go?" << endl;
                cout << "===========================" << endl;
                cout << "1. The Farm" << endl;
                cout << "2. The Mines" << endl;
                cout << "3. The Joja Mart" << endl;
                cout << "4. The Beach" << endl;
                cout << "===========================" << endl;
                cin >> choice2;
                switch(choice2) {
                    case 1: {
                        thePlayer.setLocation("Farm");
                        return true;
                        break;
                    }
                    case 2: {
                        thePlayer.setLocation("Mines");
                        return true;
                        break;
                    }
                    case 3: {
                        thePlayer.setLocation("Joja Mart");
                        return true;
                        break;
                    }
                    case 4: {
                        thePlayer.setLocation("Beach");
                        return true;
                        break;
                    }
                }
                break;
            }

            case 2: {
                int choice2;
                cout << "===========================" << endl;
                cout << "1. Talk to " << getPeople()[0].getName() << endl;
                cout << "2. Talk to " << getPeople()[1].getName() << endl;
                cout << "===========================" << endl;
                cin >> choice2;
                switch(choice2) {
                    case 1: {
                        int choice3;
                        cout << "===========================" << endl;
                        cout << "\"Oh hello there " << thePlayer.getName() << ", I'm " << getPeople()[0].getName() << " " << getPeople()[0].getDescription() << ", what can I do for you?\"" << endl;
                        cout << "===========================" << endl;
                        questCheck(0, playerQuests, inventory);

                        cout << "===========================" << endl;
                        cout << "1. \"How do I complete the bundle?\"" << endl;
                        cout << "2. \"How's Joja's influence in Stardew Valley?\"" << endl;
                        cout << "3. \"Is there anything I can help you with?\"" << endl;
                        cout << "===========================" << endl;
                        cin >> choice3;
                        switch (choice3) {
                            case 1:{
                                cout << "\"Well theres a few important things you can do." << endl;
                                cout << "For the blueberries you'll just have to buy 2 seeds from the store we got here and plant them yourself." << endl;
                                cout << "I can help you with the truffle oil myself, just ask me later if there's anything I need help with." << endl;
                                cout << "Pierre definitely has a crystal fruit so go ask him if you can help him with anything in return for the fruit." << endl;
                                cout << "The octopus you'd definitely have to ask Willy about." << endl;
                                cout << "Finally, the diamond is the thing I'm most unsure about, maybe travel to the mines and see if the Dwarf can help you. Be warned he's a tad paranoid.\"" << endl;
                                for (int i = 0; i < 5; i++) {
                                    if (bundleTracker[i] == 0) {
                                        bundleTracker[i] = 1;
                                    }
                                }
                                break;
                            }
                            case 2:{}
                            case 3: {
                                cout << endl;
                                bool isActive;
                                bool isCompleted;
                                for (int i = 0; i < 10; i++) {
                                    if (playerQuests[i].getName() == getPeople()[0].getQuest()) {
                                        isActive = playerQuests[i].getIfActive();
                                        isCompleted = playerQuests[i].getIfCompleted();
                                    } 
                                } 

                                if (!isCompleted && !isActive) {
                                    cout << "\"As a matter of fact there is. Bring me ten parsnips and I'll reward you with some truffle oil I've been holding on to.\"" << endl;
                                    for (int i = 0; i < 10; i++) {
                                        if (playerQuests[i].getName() == getPeople()[0].getQuest()) {
                                            playerQuests[i].setIfActive(1);
                                        } 
                                    } 
                                    if (bundleTracker[1] == 1) {
                                            bundleTracker[1] = 2;
                                    }
                                
                                }
                                else if (!isCompleted && isActive) {
                                    cout << "\"Yes the task I gave you earlier.\"" << endl;
                                }
                                else if(isCompleted) {
                                    cout << "\"No nothing else for now.\"" << endl;
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        int choice3;
                        cout << "===========================" << endl;
                        cout << "\"Oh hello there " << thePlayer.getName() << ", I'm " << getPeople()[1].getName() << " " << getPeople()[1].getDescription() << ", what can I do for you?\"" << endl;
                        cout << "===========================" << endl;
                        questCheck(1, playerQuests, inventory);
                        cout << "===========================" << endl;
                        cout << "1. \"How's the store doing?\"" << endl;
                        cout << "2. \"How do I buy things?\"" << endl;
                        cout << "3. \"Is there anything I can help you with?\"" << endl;
                        cout << "===========================" << endl;

                        cin >> choice3;
                        switch (choice3) {
                            case 1:{}
                            case 2:{}
                            case 3: {
                                cout << endl;
                                bool isActive;
                                bool isCompleted;
                                for (int i = 0; i < 10; i++) {
                                    if (playerQuests[i].getName() == getPeople()[1].getQuest()) {
                                        isActive = playerQuests[i].getIfActive();
                                        isCompleted = playerQuests[i].getIfCompleted();
                                    } 
                                } 

                                if (!isCompleted && !isActive) {
                                    cout << "\"Yes there is. Take this new seed that I acquired from the desert and plant it, and then bring me the result. In exchange I'll give you the crystal fruit you need for the bundle, a fruit for a fruit." << endl << "Also you can already purchase seeds of this new plant from me, I'm just giving you this one for free.\"" << endl;
                                    if (addItem(inventory,  Item("Truly luxurious fruit with a slight tangy flavor ", 1, "Starfruit seeds", 1))) {
                                        for (int i = 0; i < 10; i++) {
                                            if (playerQuests[i].getName() == getPeople()[1].getQuest()) {
                                                playerQuests[i].setIfActive(1);
                                            } 
                                        }
                                        if (bundleTracker[2] == 1) {
                                            bundleTracker[2] = 2;
                                        }
                                    }
                                    else {
                                        cout << "\"Oh sorry it looks like you don't have enough inventory space to carry this seed right now, come back later when you have space.\"" << endl;
                                    }

                                    
                                
                                }
                                else if (!isCompleted && isActive) {
                                    cout << "\"Yes the task I gave you earlier.\"" << endl;
                                }
                                else if(isCompleted) {
                                    cout << "\"No nothing else for now.\"" << endl;
                                }
                                break;
                            }
                        }
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
                    cout << "1. Buy parsnip seeds, the humblest of crops" << endl;
                    cout << "2. Sell parsnips" << endl;
                    cout << "3. Buy starfruit seeds, truly luxurious fruit with a slight tangy flavor" << endl;
                    cout << "4. Sell starfruits" << endl;
                    cout << "5. Buy blueberry seeds, grows so that one plant can produce mutiple fruit" << endl;
                    cout << "6. Sell blueberries" << endl;
                    cout << "7. Exit" << endl;
                    cout << "===========================" << endl;
                    cin >> choice2;

                    if (thePlayer.setTime()) {
                        cout << "It got too late, you passed out" << endl;
                        thePlayer.newDayOutside();
                        return true;
                    }

                    switch(choice2) {
                        case 1: {
                            buy(inventory,"Parsnip seeds", "The humblest of crops",25);
                            break;
                        }
                        case 2: {
                            sell( inventory, "Parsnip(s)" , 40);
                            break;
                        }

                        case 3: {
                            buy(inventory,"Starfruit seeds", "Truly luxurious fruit with a slight tangy flavor",50);
                            break;
                        }

                        case 4: {
                            sell( inventory, "Starfruit(s)" , 200);
                            break;
                        }

                        case 5: {
                            buy(inventory,"Blueberry seeds", "Grows so that one plant can produce mutiple fruits when harvested",35);
                            for (int i = 0; i < 10; i++) {
                                if ((inventory[i].getName() == "Blueberry seeds") && (inventory[i].getAmount() >= 2)) {
                                    if (bundleTracker[0] == 1) {
                                        bundleTracker[0] = 2;
                                    }
                                }
                            }

                            break;
                        }

                        case 6: {
                            sell( inventory, "Blueberry(s)" , 50);
                            break;
                        }
                        case 7: {
                            exit = false;
                        }
                    }
                }
                break;
            }

            case 7: {
                bool bundleComplete = 1;
                for (int i = 0; i < 5; i++) {
                    bundleCheck(i, playerQuests, inventory);
                }

                cout << "Bundle items still needed: " << endl;
                for (int i = 0; i < 5; i++) {
                    if (playerQuests[i].getIfActive()) {
                        cout << playerQuests[i].getRequirement().getAmount() << " " << playerQuests[i].getRequirement().getName() << "." << endl;
                    }
                }
                
                bundlePlanner(playerQuests,bundleTracker);
                for (int i = 0; i < 5; i++) {
                    if (!playerQuests[i].getIfCompleted()) {
                        bundleComplete = 0;
                    }
                }

                if (bundleComplete) {
                    thePlayer.setBundle(1);
                    return true;
                }
                break;
            }

            case -1: {
                return false;
            }
        }
    
    }
}

void Town::buy(Item inventory[10], std::string name, std::string description, int price) {
    int amountBought;
    cout << name << " cost " << price << " gold." << endl;
    cout << "How many would you like to purchase? ";
    cin >> amountBought;

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
    } 
    else {
        cout << "You don't have enough gold to buy that many." << endl;
    }
                            
}

void Town::sell(Item inventory[10], std::string name, int value) {
    int amountSold;
    int index;
    bool found = 0;
    cout << name << " sell for " << value << " gold each" << endl;
    for (int i = 0; i < 10; i++) {
        if (inventory[i].getName() == name) {
            index = i;
            found = 1;
            break;
        }
    }
    if (found) {
        cout << "You currently have " << inventory[index].getAmount() << " " << inventory[index].getName() << "." << endl;
        cout << "How many do you want to sell? ";
        cin >> amountSold;

    if (amountSold <= inventory[index].getAmount()) {
        inventory[index].setAmount(-amountSold);
        thePlayer.setGold(amountSold * value);
    }
    else {
        cout << "You don't have that many " << name  << "." << endl;
    }
    }
    else {
        cout << "You don't have any " << name <<  " to sell." << endl;
    }
}

bool Town::searchPlayerInventory(Item questItem , Item inventory[10]) {
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

bool Town::addItem(Item inventory[10], Item questReward) {
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

 void Town::questCheck(int p, Quest playerQuests[10], Item inventory[10]) {
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

 void Town::bundleCheck(int q, Quest playerQuests[10], Item inventory[10]) {
    if (searchPlayerInventory(playerQuests[q].getRequirement(),inventory)) {
    cout << "===========================" << endl;
    cout << "The bundle requirements you possess have been removed from your inventory and added to the bundle." << endl;
    cout << "The requirement met is " << playerQuests[q].getDescription() << "." << endl;
    cout << "===========================" << endl;
    playerQuests[q].setIfActive(0);
    playerQuests[q].setIfCompleted(1);
    }
}
 
void Town::bundlePlanner(Quest playerQuests[10], int bundleTracker[]) {
    cout << "Bundle Planner: " << endl;
    if (!playerQuests[0].getIfCompleted()) {
        cout << "Crop requirement: ";
        if (bundleTracker[0] == 0) {
            cout << "Talk to Mayor Lewis about your next step" << endl;
        }
        else if (bundleTracker[0] == 1) {
            cout << "Buy 2 blueberry seeds from Pierre's shop in town" << endl;
        }
        else if (bundleTracker[0] == 2) {
            cout << "Plant at least 2 blueberry seeds on your farm" << endl;
        }
        else if (bundleTracker[0] == 3) {
            cout << "Water the blueberry bushes you've got planted each day, after 6 days they should be harvestable" << endl;
        }
        else if (bundleTracker[0] == 4) {
            cout << "Harvest your blueberries and bring them to the bundle" << endl;
        }
    }
    if (!playerQuests[1].getIfCompleted()) {
        cout << "Animal product requirement: ";
        if (bundleTracker[1] == 0) {
            cout << "Talk to Mayor Lewis about your next step" << endl;
        }
        else if (bundleTracker[1] == 1) {
            cout << "Talk to Lewis and see if he needs help with anything" << endl;
        }
        else if (bundleTracker[1] == 2) {
            cout << "Plant 10 parnip seeds, buy some in town if you don't have any" << endl;
        }
        else if (bundleTracker[1] == 3) {
            cout << "Water the parsnips you've planted each day, after 2 days they should be harvestable" << endl;
        }
        else if (bundleTracker[1] == 4) {
            cout << "Harvest your parsnips and bring them to the Lewis" << endl;
        }
    }

    if (!playerQuests[2].getIfCompleted()) {
        cout << "Forage requirement: ";
        if (bundleTracker[2] == 0) {
            cout << "Talk to Mayor Lewis about your next step" << endl;
        }
        else if (bundleTracker[2] == 1) {
            cout << "Talk to Pierre and find out if he needs help with anything in exchange for the crystal fruit" << endl;
        }
        else if (bundleTracker[2] == 2) {
            cout << "Plant the starfruit seed Pierre gave you" << endl;
        }
        else if (bundleTracker[2] == 3) {
            cout << "Water the starfruit you've planted each day, after 4 days it should be harvestable" << endl;
        }
        else if (bundleTracker[2] == 4) {
            cout << "Harvest your starfruit and bring it to Pierre" << endl;
        }
    }
    if (!playerQuests[4].getIfCompleted()) {
        cout << "Mineral requirement: ";
        if (bundleTracker[4] == 0) {
            cout << "Talk to Mayor Lewis about your next step" << endl;
        }
        else if (bundleTracker[4] == 1) {
            cout << "Go to the mines and talk to the Dwarf about obtaining a diamond" << endl;
        }
        else if (bundleTracker[4] == 2) {
            cout << "Find three emeralds for the Dwarf" << endl;
        }
        else if (bundleTracker[4] == 3) {
            cout << "Bring your three emeralds to the Dwarf" << endl;
        }
    }
}