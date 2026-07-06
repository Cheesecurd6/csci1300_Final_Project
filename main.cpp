#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "location.hpp"
#include "villager.hpp"
#include "Item.hpp"
#include "Farm.hpp"
#include "Crop.hpp"
using namespace std;

// First finish farm
//. Make farm function
//.   Crop planting and watering
//.   Sleeping
//. Somehow relate farm and player/inventory so seeds can be planted
//. Item class related to Player class through inventory

//. You'll have to hardcode seed positions in inventory




void whereAmI(std::string name,std::string location) {
    cout << "Hi " << name << " you're currently at " << location << endl;
}




int main() {
    Player mainPlayer;
    Farm farm;
    std::string farmName;
    Item parsnipSeeds("The humblest of crops", 10, 30, "Parnsnip", 1);
    Item starfruitSeeds("Truly luxurious fruit with a slight tangy flavor ", 0, 100, "Starfruit", 1);
    Item blueberrySeeds("Grows so that one plant can produce fruit mutiple times", 2, 50, "Blueberry", 1);
    Item inventory[10] {parsnipSeeds,starfruitSeeds,blueberrySeeds};

    std::cout << "Welcome to my final project" << std::endl << std::endl << std::endl;
    mainPlayer.setEnergy(100);
    mainPlayer.setName();

    std::cout << "What's the name of your farm? ";
    getline(std::cin , farmName);
    farm.setName(farmName);

    mainPlayer.setLocation(farm.getName());

    whereAmI(mainPlayer.getName(),mainPlayer.getLocation());

    farm.farmTerminal(mainPlayer,inventory);

    cout << farm.getHowManyParsnipsPlanted() << endl;

}   