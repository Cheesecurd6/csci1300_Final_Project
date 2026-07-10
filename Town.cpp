#include <string>
#include <vector>
#include <iostream>
#include "location.h"
#include "Crop.h"
#include "player.h"
#include "Item.h"
#include "Town.h"
using namespace std;

Town::Town(std::string n, std::vector<Villager> people) : Location(n, people) {}

Player Town::getThePlayer() {
    return thePlayer;
}

bool Town::townTerminal(Player p, Item inventory[10]) {
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
        cout << "-1. Exit the game" << endl;
        cout << "===========================" << endl;
        cin >> choice;
        if (thePlayer.setTime()) {
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
            }

            case 2: {

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
                    cout << "1. Buy parsnip seeds." << endl;
                    cout << "2. Sell parsnips" << endl;
                    cout << "3. Buy starfruit seeds." << endl;
                    cout << "4. Sell starfruits" << endl;
                    cout << "5. Buy blueberry seeds." << endl;
                    cout << "6. Sell blueberries" << endl;
                    cout << "7. Exit" << endl;
                    cout << "===========================" << endl;
                    cin >> choice2;

                    if (thePlayer.setTime()) {
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
                            buy(inventory,"Blueberry seeds", "Grows so that one plant can produce fruit mutiple times",35);
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

            case -1: {
                return false;
            }
        }
    
    }
}

void Town::buy(Item inventory[10], std::string name, std::string description, int price) {
    int amountBought;
    cout << name << "cost " << price << " gold" << endl;
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