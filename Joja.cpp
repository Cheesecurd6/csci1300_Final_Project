#include <string>
#include <vector>
#include <iostream>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "Town.h"
#include "Joja.h"

using namespace std;

Joja::Joja(std::string n, std::vector<Villager> people, int l) : Location(n,people,l){}

void Joja::buy(Item inventory[10], std::string name, std::string description, int price) {

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

void Joja::sell(Item inventory[10], std::string name, int value) {

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

bool searchPlayerInventory(Item questItem, Item inventory[10]) {
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

bool jojaTerminal(Player p, Item inventory[], Quest playerQuests[], int bundleTracker[]) {
    
}
