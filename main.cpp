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


void farmTerminal(Player p, Farm l, Item inventory[]) {
    // Overview of what can be done on the farm
    while(true) {
        int choice;
        cout << "What would you like to do next? " << endl;
        cout << "1. Leave the " << l.getName() << endl;
        cout << "2. Tend to the farm" << endl;
        cout << "3. Sleep" << endl;
        cout << "4. Check inventory" << endl;
        cout << "5. Check quests" << endl;
        cout << "-1. Exit the game" << endl;
        cin >> choice;

        switch(choice) {

            case 1: {
                cout << "Leaving the farm!" << endl;
                break;
            }

            case 2: {
                // Overview of what tending can be done
                int count = 1;
                int choice2;
                while(true) {
                cout << "You have " << p.getEnergy() << " energy." << endl;
                for (int i = 0; i < 10; i++) {
                    if (inventory[i].getSeed()) {
                        cout << "You have " << inventory[i].getAmount() << " seeds." << endl;
                    }
                }

                cout << "You have " << l.getHowManyParsnipsPlanted() << " parsnips planted and " << l.getHowManyParsnipsUnwatered() << "unwatered." << endl;
                cout << "You have " << l.getHowManyStarfruitsPlanted() << " starfruit planted and " << l.getHowManyStarfruitsUnwatered() << "unwatered." << endl;
                cout << "You have " << l.getHowManyBlueberriesPlanted() << " blueberry bushes planted and " << l.getHowManyBlueberriesUnwatered() << "unwatered." << endl;
                cout << endl;
                cout << "What would you like to do?" << endl;
                for (int i = 0; i < 10; i++) {
                    if (inventory[i].getSeed()) {
                        cout << count << ". Plant " << inventory[i].getName() << " seeds." << endl;
                        count++;
                    }
                }
                cin >> choice2;
                    switch (choice2) {

                    }
                break;
                }
            }

            
            case -1: {
                return;
            }


        }
    }
}

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

    farmTerminal(mainPlayer, farm, inventory);

}   