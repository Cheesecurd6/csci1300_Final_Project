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






void gameEnd(Player thePlayer) {
    // Different endings depending on how much help the player got from Joja
    cout << "===========================" << endl;
    if(thePlayer.getJojaInfluence() <= 2 ) {
        cout << "You managed to complete the final bundle in time with little to no help from Joja. The villagers of Stardew Valley rejoice at the refurbished Community Center and stand together in solidarity against Joja." << endl;
        cout << "You win!" << endl;
    }
    else if (thePlayer.getJojaInfluence() == 3) {
        cout << "The Community Center is completed but with noticable help from Joja. The townsfolk recognize that and don't stand completely against Joja. However, they still support each other and Pierre is still the main grocer in town." << endl;
        cout << "You win!" << endl;
    }
    else {
        cout << "With a large amount of help from Joja you complete the final bundle and rebuild the Community Center. As a result although the town's community is made stronger by the Community Center they also flock to Joja. Pierre is forced to go out of business and the long shadow of the Joja corporation is cast across the town." << endl;
        cout << "You win?" << endl;
    }
    cout << "===========================" << endl;
}




int main() {
    // Initializes the player and villagers at each location;
    Player mainPlayer;
    vector<Villager> townPeople{};
    vector<Villager> farmPeople;
    vector<Villager> beachPeople{Villager("the town's local fisherman", "Willy","Supply Issues")};
    vector<Villager> minePeople {Villager("the only dwarf left", "The Dwarf", "The Crown Jewels")};
    vector<Villager> jojaPeople {Villager("the local Joja representative", "Morris", "N/A")};

    //Reads in the info for the town villagers
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

    
    // All the quests in the game
    Quest playerQuests[9] = {
                            Quest("Bring 10 blueberries to the final bundle in town", "Complete the final bundle's crops requirement", Item("being one step closer to finishing the bundle"),Item("Grows so that one plant can produce fruit mutiple times ", 10, "Blueberry(s)", 0),1,0),
                            Quest("Bring truffle oil to the final bundle in town", "Complete the final bundle's animal product requirement", Item("being one step closer to finishing the bundle"), Item("Truffle oil smells funky but can be used to cook amazing dishes",1,"Truffle Oil",0),1,0),
                            Quest("Bring a crystal fruit to the final bundle in town", "Complete the final bundle's forage requirement", Item("being one step closer to finishing the bundle"), Item("A prize fruit, often only foraged during the winter or collected from the coldest depths of the mines",1,"Crystal Fruit",0),1,0),
                            Quest("Bring an octopus to the final bundle in town", "Complete the final bundle's fish requirement", Item("being one step closer to finishing the bundle"),Item("A mysterious creature from the depths of the ocean; delicious with a little lemona and salt", 1, "Octopus",0),1,0),
                            Quest("Bring a diamond to the final bundle in town", "Complete the final bundle's mineral requirement", Item("being one step closer to finishing the bundle"),Item("Shiny shiny", 1, "Diamond(s)", 0),1,0),
                            Quest("Gather 10 parsnips and give them to Mayor Lewis, free of charge, in exchange for a reward","Bring Lewis his parsnips", Item("Truffle oil smells funky but can be used to cook amazing dishes",1,"Truffle Oil",0), Item("The humblest of crops" , 10, "Parsnip(s)", 0),0,0 ), 
                            Quest("Take the starfruit seed Pierre gave you and plant it. Deliver to him the final product","Research for Pierre",Item("A prize fruit, often only foraged during the winter or collected from the coldest depths of the mines",1,"Crystal Fruit",0), Item("Truly luxurious fruit with a slight tangy flavor", 1 , "Starfruit(s)",0 ),0,0),
                            Quest("Fish at the beach for 5 tuna and then bring them to Willy", "Supply Issues", Item("The very base bait available on the market",1,"Deluxe Bait", 0), Item("One of the more valuable fish in the sea", 5, "Tuna", 0),0,0),
                            Quest("Venture into the mines and find three emeralds for the Dwarf","The Crown Jewels", Item("Shiny shiny", 1, "Diamond(s)", 0), Item("A lovely shade of green with an enchanting shimmer", 3, "Emerald(s)",0),0,0)
                        };
    // All locations
    Farm farm("Farm", farmPeople,0);
    Town town("Town", townPeople,0);
    Mines mines("Mines",minePeople,0);
    Beach beach("Beach",beachPeople,0);
    Joja jojaMart("Joja Mart",jojaPeople,0);

    Item parsnipSeeds("The humblest of crops " , 10, "Parsnip seeds", 1);
    Item inventory[10] {parsnipSeeds};
    int bundleTracker[5] {0,0,0,0,0};

    std::cout << "Welcome to my final project" << std::endl << std::endl << std::endl;
    cout << "===========================" << endl;
    cout << "You're the newest farmer in Stardew Valley. You've been here almost a year now and have been steadily working to complete the town's community center and get it refurbished. Now only one last obstacle stands in your way, the final bundle. Various items that can be collected across the local area. Work with the townspeople to collect them or sellout to Joja Mart and just buy them. The choice is your. You have 10 days to get the job done, each day has 20 turns." << endl;
    cout << "Explore the valley and tend to your farm. Get tips from the locals. If you need any help on what to do next check the bundle in town. Also, if your doing any action that'll give you an item make sure to have the space needed for that item or you will lose it permanently." << endl;
    cout << "Good luck!" << endl;
    cout << "===========================" << endl;
    mainPlayer.setEnergy(100);
    mainPlayer.setName();
    mainPlayer.setLocation(farm.getName());

    // Tracks if the Player still wants to play
    bool gameOn = true;
    while (gameOn) {
        if (mainPlayer.getBundle()) {
            // Once the bundle is complete
            cout << "Congratulations you've completed the final bundle!" << endl;
            //Different ending function
            gameEnd(mainPlayer);
            break;
        }
        if (mainPlayer.getDay() == 10) {
            // Once the player runs out of time
            cout << "===========================" << endl;
            cout << "Game over" << endl;
            cout << "You failed to complete the final bundle in time. As a result the town stagnates and the Community Center falls back into disrepair." << endl;
            cout << "You lose." << endl;
            cout << "===========================" << endl;
            break;
        }

        // While the game is on this loop constantly runs and checks the player's location
        // Depending on the location the player then enters that location's menu
        // A copy of the player is sent into the location, everything else inventory, quests, and bundle progress is passed by reference
        // The menu is a bool function so when the player exits that location it'll return true if the player still wants to play or false if not
        // Then, if the player is still playing, the copy of the player is passed out and assigned to the old version of the player
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
            gameOn = jojaMart.jojaTerminal(mainPlayer,inventory,playerQuests);
            mainPlayer = jojaMart.getThePlayer();
        }
    }


}   