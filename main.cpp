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
#include "Quest.h"
using namespace std;






void whereAmI(std::string name,std::string location) {
    cout << "Hi " << name << " you're currently at the" << location << endl;
}




int main() {
    Player mainPlayer;
    vector<Villager> farmPeople;
    vector<Villager> townPeople {Villager("the town's mayor", "Lewis","Bring Lewis his parsnips"),Villager("the local storekeep for the general store we got here", "Pierre","Research for Pierre")};
    Quest playerQuests[10] = {Quest("Gather 10 parsnips and give them to Mayor Lewis, free of charge, in exchange for a reward","Bring Lewis his parsnips", Item("Truffle oil smells funky but can be used to cook amazing dishes",1,"Truffle Oil",0), Item("The humblest of crops" , 10, "Parsnip(s)", 0),0,0 ), 
                              Quest("Take the starfruit seed Pierre gave you and plant it. Deliver to him the final product","Research for Pierre",Item("A prize fruit, often only foraged during the winter or collected from the coldest depths of the mines",1,"Crystal Fruit",0), Item("Truly luxurious fruit with a slight tangy flavor", 1 , "Starfruit(s)",0 ),0,0)};
    Farm farm("Farm", farmPeople);
    Town town("Town", townPeople);
    std::string farmName;
    Item parsnipSeeds("The humblest of crops " , 10, "Parsnip seeds", 1);
    Item starfruitSeeds("Truly luxurious fruit with a slight tangy flavor ", 15, "Starfruit seeds", 1);
    Item blueberrySeeds("Grows so that one plant can produce fruit mutiple times ", 5, "Blueberry seeds", 1);
    Item inventory[10] {parsnipSeeds,starfruitSeeds,blueberrySeeds};

    std::cout << "Welcome to my final project" << std::endl << std::endl << std::endl;
    mainPlayer.setEnergy(100);
    mainPlayer.setName();
    farm.setName("Farm");

    mainPlayer.setLocation(farm.getName());
    bool gameOn = true;
    while (gameOn) {
        if (mainPlayer.getDay() == 10) {
            cout << "Game over" << endl;
            break;
        }
        if (mainPlayer.getLocation() == "Farm") {
            gameOn = farm.farmTerminal(mainPlayer,inventory);
            mainPlayer = farm.getThePlayer();
        }
        else if (mainPlayer.getLocation() == "Town") {
            gameOn = town.townTerminal(mainPlayer,inventory,playerQuests);
            mainPlayer = town.getThePlayer();
        }
    }


}   