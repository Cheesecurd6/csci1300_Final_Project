#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "location.h"
#include "villager.h"
#include "Item.h"
#include "Farm.h"
#include "Crop.h"
#include "Town.h"
using namespace std;






void whereAmI(std::string name,std::string location) {
    cout << "Hi " << name << " you're currently at the" << location << endl;
}




int main() {
    Player mainPlayer;
    vector<Villager> farmPeople;
    vector<Villager> townPeople;
    Farm farm("Farm", farmPeople);
    Town town("Town", townPeople);
    std::string farmName;
    Item parsnipSeeds("The humblest of crops " , 10, 30, "Parsnip seeds", 1);
    Item starfruitSeeds("Truly luxurious fruit with a slight tangy flavor ", 15, 100, "Starfruit seeds", 1);
    Item blueberrySeeds("Grows so that one plant can produce fruit mutiple times ", 5, 50, "Blueberry seeds", 1);
    Item inventory[10] {parsnipSeeds,starfruitSeeds,blueberrySeeds};

    std::cout << "Welcome to my final project" << std::endl << std::endl << std::endl;
    mainPlayer.setEnergy(100);
    mainPlayer.setName();
    farm.setName("Farm");

    mainPlayer.setLocation(farm.getName());
    bool gameOn = true;
    while (gameOn) {
        if (mainPlayer.getDay() == 5) {
            cout << "Game over" << endl;
            break;
        }
        if (mainPlayer.getLocation() == "Farm") {
            gameOn = farm.farmTerminal(mainPlayer,inventory);
            mainPlayer = farm.getThePlayer();
        }
        else if (mainPlayer.getLocation() == "Town") {
            gameOn = town.townTerminal(mainPlayer,inventory);
            mainPlayer = town.getThePlayer();
        }
    }


}   