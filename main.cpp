#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "location.hpp"
using namespace std;

// First finish farm
//. Make farm function
//.   Crop planting and watering
//.   Sleeping
//. Somehow relate farm and player/inventory so seeds can be planted
//. Item class related to Player class through inventory


void farmTerminal(int seeds, int energy) {
    while(true) {
        int choice;
        cout << "What would you like to do next? ";
        cout << "1. Leave the farm" << endl;
        cout << "2. Tend to the farm" << endl;
        cout << "3. Sleep" << endl;
        cout << "4. Check inventory" << endl;
        cout << "5. Check quests" << endl;
        cout << "-1. Exit the game" << endl;
        cin >> choice;
    }
}

void whereAmI(std::string name,std::string location) {
    cout << "Hi " << name << " you're currently at " << location << endl;
}




int main() {
    Player main;
    Location farm;
    std::string farmName;

    std::cout << "Welcome to my final project" << std::endl << std::endl << std::endl;
    main.setName();

    std::cout << "What's the name of your farm? ";
    getline(std::cin , farmName);
    farm.setName(farmName);

    main.setLocation(farm.getName());

    whereAmI(main.getName(),main.getLocation());

}   