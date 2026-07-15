#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "player.h"
#include "location.h"
#include "villager.h"
#include "Item.h"
#include "Farm.h"
#include "Crop.h"
#include "Town.h"
#include "Quest.h"
#include "Mines.h"
#include "Beach.h"
#include "Joja.h"
using namespace std;






void whereAmI(std::string name,std::string location) {
    cout << "Hi " << name << " you're currently at the" << location << endl;
}




int main() {
    vector<Villager> townPeople{};
    Player mainPlayer;
    vector<Villager> farmPeople;
    vector<Villager> beachPeople{Villager("the town's local fisherman", "Willy","Supply Issues")};
    vector<Villager> minePeople {Villager("the only dwarf left", "The Dwarf", "The Crown Jewels")};
    vector<Villager> jojaPeople {Villager("the local Joja representative", "Morris", "N/A")};

    ifstream inFile("townVillager.txt");
    if (!inFile.is_open()) {
        cout << "Error: could not open townVillager.txt" << endl;
        return 1;
    }
    string line;
    while (getline(inFile, line)) {
        string description;
        string name;
        string quest;
        int comma1 = line.find(",");
        description = line.substr(0, comma1);
        int comma2 = line.find(",",comma1 + 1);
        name = (line.substr(comma1 + 1, (comma2 - comma1 -1)));
        int comma3 = line.find(",",comma2 + 1);
        quest = (line.substr(comma2 + 1, (comma3 - comma2 -1)));
        townPeople.push_back(Villager(description,name,quest));
    }
    inFile.close();

    

    Quest playerQuests[10] = {
                            Quest("Bring 10 blueberries to the final bundle in town", "Complete the final bundle's crops requirement", Item("being one step closer to finishing the bundle"),Item("Grows so that one plant can produce fruit mutiple times ", 10, "Blueberry(s)", 0),1,0),
                            Quest("Bring truffle oil to the final bundle in town", "Complete the final bundle's animal product requirement", Item("being one step closer to finishing the bundle"), Item("Truffle oil smells funky but can be used to cook amazing dishes",1,"Truffle Oil",0),1,0),
                            Quest("Bring a crystal fruit to the final bundle in town", "Complete the final bundle's forage requirement", Item("being one step closer to finishing the bundle"), Item("A prize fruit, often only foraged during the winter or collected from the coldest depths of the mines",1,"Crystal Fruit",0),1,0),
                            Quest("Bring an octopus to the final bundle in town", "Complete the final bundle's fish requirement", Item("being one step closer to finishing the bundle"),Item("A mysterious creature from the depths of the ocean; delicious with a little lemona and salt", 1, "Octopus",0),1,0),
                            Quest("Bring a diamond to the final bundle in town", "Complete the final bundle's mineral requirement", Item("being one step closer to finishing the bundle"),Item("Shiny shiny", 1, "Diamond(s)", 0),1,0),
                            Quest("Gather 10 parsnips and give them to Mayor Lewis, free of charge, in exchange for a reward","Bring Lewis his parsnips", Item("Truffle oil smells funky but can be used to cook amazing dishes",1,"Truffle Oil",0), Item("The humblest of crops" , 10, "Parsnip(s)", 0),0,0 ), 
                            Quest("Take the starfruit seed Pierre gave you and plant it. Deliver to him the final product","Research for Pierre",Item("A prize fruit, often only foraged during the winter or collected from the coldest depths of the mines",1,"Crystal Fruit",0), Item("Truly luxurious fruit with a slight tangy flavor", 1 , "Starfruit(s)",0 ),0,0),
                            Quest("Fish at the beach for 5 tuna and then bring them to Willy", "Supply Issues", Item("The very base bait available on the market",1,"Deluxe Bait", 0), Item("One of the more valuable fish in the sea", 5, "Tuna", 0),0,0),
                            Quest("Venture into the mines and find an emerald for the Dwarf","The Crown Jewels", Item("Shiny shiny", 1, "Diamond(s)", 0), Item("A lovely shade of green with an enchanting shimmer", 3, "Emerald(s)",0),0,0)
                        };
    Farm farm("Farm", farmPeople,0);
    Town town("Town", townPeople,0);
    Mines mines("Mines",minePeople,0);
    Beach beach("Beach",beachPeople,0);
    Joja jojaMart("Joja Mart",jojaPeople,0);
    std::string farmName;
    Item parsnipSeeds("The humblest of crops " , 10, "Parsnip seeds", 1);
    //Item starfruitSeeds("Truly luxurious fruit with a slight tangy flavor ", 15, "Starfruit seeds", 1);
    //Item blueberrySeeds("Grows so that one plant can produce fruit mutiple times ", 5, "Blueberry seeds", 1);
    Item inventory[10] {parsnipSeeds};
    int bundleTracker[5] {0,0,0,0,0};

    std::cout << "Welcome to my final project" << std::endl << std::endl << std::endl;
    mainPlayer.setEnergy(100);
    mainPlayer.setName();
    farm.setName("Farm");

    mainPlayer.setLocation(farm.getName());
    bool gameOn = true;
    while (gameOn) {
        if (mainPlayer.getBundle()) {
            cout << "Congratulations you win!" << endl;
            break;
        }
        if (mainPlayer.getDay() == 10) {
            cout << "Game over" << endl;
            break;
        }
        if (mainPlayer.getLocation() == "Farm") {
            gameOn = farm.farmTerminal(mainPlayer,inventory, playerQuests,bundleTracker);
            mainPlayer = farm.getThePlayer();
        }
        else if (mainPlayer.getLocation() == "Town") {
            gameOn = town.townTerminal(mainPlayer,inventory,playerQuests,bundleTracker);
            mainPlayer = town.getThePlayer();
        }
        else if(mainPlayer.getLocation() == "Mines") {
            gameOn = mines.mineTerminal(mainPlayer,inventory,playerQuests,bundleTracker);
            mainPlayer = mines.getThePlayer();
        }
        else if(mainPlayer.getLocation() == "Beach") {
            gameOn = beach.beachTerminal(mainPlayer,inventory,playerQuests,bundleTracker);
            mainPlayer = beach.getThePlayer();
        }
        else if(mainPlayer.getLocation() == "Joja Mart") {
            gameOn = jojaMart.jojaTerminal(mainPlayer,inventory,playerQuests,bundleTracker);
            mainPlayer = jojaMart.getThePlayer();
        }
    }


}   