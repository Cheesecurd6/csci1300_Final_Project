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
                    cout << "What do you want buy/sell?" << endl;
                    cout << "You currently have " << thePlayer.getGold() << " gold" << endl;
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
                            int amountBought;
                            cout << "Parsnips seeds cost 25 gold" << endl;
                            cout << "How many would you like to purchase? ";
                            cin >> amountBought;

                            if (amountBought * 25 <= thePlayer.getGold()) {
                                bool spaceFound = false;
                            for (unsigned int i = 0; i < 10; i++) {
                                if (inventory[i].getName() == "Parsnip seeds" && !(inventory[i].getAmount() == 0)) {
                                    spaceFound = true;
                                    inventory[i].setAmount(amountBought);
                                    thePlayer.setGold(-(amountBought * 25));
                                    break;
                                    }
                                }
                            for (unsigned int i = 0; i < 10; i++) {
                                if (spaceFound == true) {break;}
                                if (inventory[i].getAmount() == 0) {
                                    spaceFound = true;
                                    inventory[i] = Item ("Seeds for parsnips",amountBought,25, "Parsnip seeds",1);
                                    thePlayer.setGold(-(amountBought * 25));
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
                            break;
                        }
                        case 2: {
                            int amountSold;
                            int parsnipIndex;
                            bool parsnipFound = 0;
                            cout << "Parsnips sell for 35 gold each" << endl;
                            for (int i = 0; i < 10; i++) {
                                if (inventory[i].getName() == "Parsnip(s)" && inventory[i].getAmount() > 0) {
                                    parsnipIndex = i;
                                    parsnipFound = 1;
                                    break;
                                }
                            }
                            if (parsnipFound) {
                                cout << "You currently have " << inventory[parsnipIndex].getAmount() << " " << inventory[parsnipIndex].getName() << "." << endl;
                                cout << "How many do you want to sell? ";
                                cin >> amountSold;

                            if (amountSold <= inventory[parsnipIndex].getAmount()) {
                                inventory[parsnipIndex].setAmount(-amountSold);
                                thePlayer.setGold(amountSold * 35);
                            }
                            else {
                                cout << "You don't have that many parsnips" << endl;
                            }
                            }
                            else {
                                cout << "You don't have any parsnips to sell" << endl;
                            }
                            break;
                        }

                        case 3: {
                            int amountBought;
                            cout << "Starfruit seeds cost 50 gold" << endl;
                            cout << "How many would you like to purchase? ";
                            cin >> amountBought;

                            if (amountBought * 50 <= thePlayer.getGold()) {
                                bool spaceFound = false;
                                for (unsigned int i = 0; i < 10; i++) {
                                    if (inventory[i].getName() == "Starfruit seeds" && !(inventory[i].getAmount() == 0)) {
                                        spaceFound = true;
                                        inventory[i].setAmount(amountBought);
                                        thePlayer.setGold(-(amountBought * 50));
                                        break;
                                        }
                                    }
                                for (unsigned int i = 0; i < 10; i++) {
                                    if (spaceFound == true) {break;}
                                    if (inventory[i].getAmount() == 0) {
                                        spaceFound = true;
                                        inventory[i] = Item ("Seeds for starfruit",amountBought,50, "Starfruit seeds",1);
                                        thePlayer.setGold(-(amountBought * 50));
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
                            break;
                        }

                        case 4: {
                            int amountSold;
                            int starfruitIndex;
                            bool starfruitFound = 0;
                            cout << "Starfruits sell for 200 gold each" << endl;
                            for (int i = 0; i < 10; i++) {
                                if (inventory[i].getName() == "Starfruit(s)" && inventory[i].getAmount() > 0) {
                                    starfruitIndex = i;
                                    starfruitFound = 1;
                                    break;
                                }
                            }
                            if (starfruitFound) {
                                cout << "You currently have " << inventory[starfruitIndex].getAmount() << " " << inventory[starfruitIndex].getName() << "." << endl;
                                cout << "How many do you want to sell? ";
                                cin >> amountSold;

                            if (amountSold <= inventory[starfruitIndex].getAmount()) {
                                inventory[starfruitIndex].setAmount(-amountSold);
                                thePlayer.setGold(amountSold * 200);
                            }
                            else {
                                cout << "You don't have that many starfruits" << endl;
                            }
                            }
                            else {
                                cout << "You don't have any starfruits to sell" << endl;
                            }
                            break;
                        }

                        case 5: {
                            int amountBought;
                            cout << "Blueberry seeds cost 35 gold" << endl;
                            cout << "How many would you like to purchase? ";
                            cin >> amountBought;

                            if (amountBought * 35 <= thePlayer.getGold()) {
                                bool spaceFound = false;
                                for (unsigned int i = 0; i < 10; i++) {
                                    if (inventory[i].getName() == "Blueberry seeds" && !(inventory[i].getAmount() == 0)) {
                                        spaceFound = true;
                                        inventory[i].setAmount(amountBought);
                                        thePlayer.setGold(-(amountBought * 35));
                                        break;
                                        }
                                    }
                                for (unsigned int i = 0; i < 10; i++) {
                                    if (spaceFound == true) {break;}
                                    if (inventory[i].getAmount() == 0) {
                                        spaceFound = true;
                                        inventory[i] = Item ("Seeds for blueberries",amountBought,35, "Blueberry seeds",1);
                                        thePlayer.setGold(-(amountBought * 35));
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
                            break;
                        }

                        case 6: {
                            int amountSold;
                            int blueberryIndex;
                            bool blueberryFound = 0;
                            cout << "Blueberries sell for 50 gold each" << endl;
                            for (int i = 0; i < 10; i++) {
                                if (inventory[i].getName() == "Blueberry(s)" && inventory[i].getAmount() > 0) {
                                    blueberryIndex = i;
                                    blueberryFound= 1;
                                    break;
                                }
                            }
                            if (blueberryFound) {
                                cout << "You currently have " << inventory[blueberryIndex].getAmount() << " " << inventory[blueberryIndex].getName() << "." << endl;
                                cout << "How many do you want to sell? ";
                                cin >> amountSold;

                            if (amountSold <= inventory[blueberryIndex].getAmount()) {
                                inventory[blueberryIndex].setAmount(-amountSold);
                                thePlayer.setGold(amountSold * 50);
                            }
                            else {
                                cout << "You don't have that many blueberries" << endl;
                            }
                            }
                            else {
                                cout << "You don't have any blueberries to sell" << endl;
                            }
                            break;
                        }
                        break;
                    }
                }

            }

            case -1: {
                return false;
            }
        }
    
    }
}