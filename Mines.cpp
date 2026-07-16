#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Mines.h"
#include "Validation.h"

using namespace std;

Mines::Mines(std::string n, std::vector<Villager> people, int l) : Location(n,people,l){}


Player Mines::getThePlayer() {
  return thePlayer;
}
void Mines::Mine (Item inventory[]) {
  int roll;
  int choice;
  bool found = false;
  if (thePlayer.getWeather() == 3) {
        luck++;
  }
  std::mt19937 mt{std::random_device{}()};
  std::uniform_int_distribution<> d1000{ 1, 1000 };
  std::uniform_int_distribution<> weighted1000 {600,1000};
  std::uniform_int_distribution<> doubleWeighted1000 {700,1000};
  for (int i = 0; i < 10; i++) {
    if (inventory[i].getName() == "Bomb") {
        if(inventory[i].getAmount() >= 0) {
            found = true;
        }
    }
  }
  if (found) {
    cout << "===========================" << endl;
    cout << "Do you want to use a bomb?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "===========================" << endl;
    choice = promptInt(1,2);

    if (choice == 1) {
      if (searchPlayerInventory(Item("Explosive device used in the mines", 1 , "Bomb", 100), inventory)) {
        luck++;
      }
    }
  }
  if (luck == 2) {
    roll = doubleWeighted1000(mt);
  }
  else if (luck == 1) {
    roll = weighted1000(mt);
  }
  else {
    roll = d1000(mt);
  }

  if (roll >= 999) {
    cout << "\"You've freed me from my entrapment by that witch. As a reward I give you a mineral prized among you folk, a diamond.\"" << endl;
    if (addItem(inventory,Item ("Shiny shiny", 1, "Diamond(s)", 0))) {
      cout << "\"Here you go!\"" << endl;
    }
    else {
      cout << "\"Oh no! It looks like you don't have any inventory space. Oh well I guess I can't give this to you after all.\"" << endl;
    }
  }
  else if (roll >= 850) {
    cout << "While splitting apart a particularly troublesome rock something green and very shiny pops out. It's an emerald!" << endl;
    if (addItem(inventory, Item("A lovely shade of green with an enchanting shimmer", 1, "Emerald(s)",0))) {}
    else {
      cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
  }
  else if (roll >= 750) {
    cout << "On a very chilly level of the mines you stumble across a reflective blue mineral just laying on the ground. It's a frozen tear!" << endl;
    if (addItem(inventory, Item("A crystal teardrop rumored to be the result of a yeti crying", 1, "Frozen Tear(s)", 0))){}
    else {
      cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
  }
  else if (roll >= 600) {
    cout << "You find a node of yellow shiny material and break it open inside you find something. It's gold ore!" << endl;
    if(addItem(inventory, Item("Very valuable and shiny", 1, "Gold Ore", 0))){}
    else {
      cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
  }
  else if (roll >= 300) {
    cout << "Upon cracking open a node of ore you find something. It's iron ore!" << endl;
    if (addItem(inventory, Item("Durable and versatile iron is very prized, albeit less than gold", 2, "Iron Ore", 0))){}
    else {
      cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
  }
  else {
    cout << "Breaking open a node of ore you find something. It's copper ore!" << endl;
    if (addItem(inventory, Item("Often looked down upon, but still has many applications", 3, "Copper Ore", 0))){}
    else {
      cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
  } 
  luck = 0;
}
bool Mines::searchPlayerInventory(Item questItem, Item inventory[10]) {
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
void Mines::questCheck(int p, Quest playerQuests[10], Item inventory[10]) {
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
void Mines::buy(Item inventory[10], std::string name, std::string description, int price) {
  int amountBought;
  cout << name << " cost " << price << " gold." << endl;
  cout << "How many would you like to purchase? ";
  amountBought = promptInt(0,1000);

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
void Mines::sell(Item inventory[10], std::string name, int value) {
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
      amountSold = promptInt(0,1000);

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
bool Mines::addItem(Item inventory[10], Item questReward) {
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

bool Mines::mineTerminal(Player p, Item inventory[], Quest playerQuests[], int bundleTracker[]) {
  thePlayer = p;

  while(true) {
    int choice;
    for (int i = 0; i < 10; i++) {
      if ((inventory[i].getName() == "Emerald(s)") && (inventory[i].getAmount() >= 3)) {
        if (bundleTracker[4] <= 2) {
          bundleTracker[4] = 3;
        }
      }
    }
    cout << endl << endl;
    cout << "Day: " << thePlayer.getDay() << " Time: " << thePlayer.getTime() << endl;
    cout << "What would you like to do next? " << endl;
    //First menu
    cout << "===========================" << endl;
    cout << "1. Leave the " << getName() << endl;
    cout << "2. Talk to the dwarf" << endl;
    cout << "3. Check inventory" << endl;
    cout << "4. Check quests" << endl;
    cout << "5. Check map" << endl;
    cout << "6. Sell/Buy items to the dwarf" << endl;
    cout << "7. Go mining, takes double the time of other actions" << endl;
    cout << "0. Exit the game" << endl;
    cout << "===========================" << endl;
    choice = promptInt(0,7);
    if (thePlayer.setTime()) {
        cout << "It got too late, you passed out" << endl;
        thePlayer.newDayOutside();
        return true;
    }
    switch(choice) {
      case 1: {
        cout << "Leaving the mines! Going to town." << endl;
        thePlayer.setLocation("Town");
        return true;
        break;
      }
      case 2: {
        int choice3;
        cout << "===========================" << endl;
        cout << "\"Oh hello there " << thePlayer.getName() << ", I'm " << getPeople()[0].getName() << " " << getPeople()[0].getDescription() << ", are you a spy for the shadow people?\"" << endl;
        cout << "===========================" << endl;
        questCheck(0, playerQuests, inventory);

        cout << "===========================" << endl;
        cout << "1. \"What will I find in the mines?\"" << endl;
        cout << "2. \"How can I find better more valuable things in the mines?\"" << endl;
        cout << "3. \"How can I obtain a diamond?\"" << endl;
        cout << "===========================" << endl;
        choice3 = promptInt(1,3);
        switch (choice3) {
            case 1:{
              cout << "\"There's a lot of different things you might find down there." << endl;
              cout << "Copper, iron, and gold ore are a given." << endl;
              cout << "Frozen tears on the colder levels." << endl;
              cout << "Emeralds are definitely one of the most valuable things down there." << endl;
              cout << "Finally, the elusive diamond, legend has it that a magical fairy trapped deep in the mines possess one. She will give it to whatever brave hero finally frees her.\"" << endl;
              cout << "The Dwarf stares at you and then bursts out laughing." << endl;
              cout << "\"No such fairy exists of course, I'm the only person who possesses a diamond. If you help me out I might just give it to you.\"" << endl;
              break;
            }
            case 2:{
              cout << "\"If you're having trouble finding more valuable items consider buying some bombs from me or coming on a stormy day.\"" << endl;
              cout << "\"Both those things increase your luck.\"" << endl;
              break;
            }
            case 3: {
                cout << endl;
                bool isActive = false;
                bool isCompleted = false;
                for (int i = 0; i < 10; i++) {
                    if (playerQuests[i].getName() == getPeople()[0].getQuest()) {
                        isActive = playerQuests[i].getIfActive();
                        isCompleted = playerQuests[i].getIfCompleted();
                    } 
                } 

                if (!isCompleted && !isActive) {
                    cout << "\"I could give you a diamond, but first you'll need to help me. I'm creating a bit of a memorial right now for my species, the crowning gems of the monument will be three emeralds. Dig deep in the mines and find them for me.\"" << endl;
                      for (int i = 0; i < 10; i++) {
                          if (playerQuests[i].getName() == getPeople()[0].getQuest()) {
                              playerQuests[i].setIfActive(1);
                          } 
                      }
                      if (bundleTracker[4] <= 1) {
                        bundleTracker[4] = 2;
                      }
                }
                else if (!isCompleted && isActive) {
                    cout << "\"Yes the task I gave you earlier.\"" << endl;
                }
                else if(isCompleted) {
                    cout << "\"No nothing else for now.\"" << endl;
                }
                break;
            }
        }
        break;         
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
        bool hasQuests = false;
        cout << "Your bundle quests are: " << endl;
        for (int i = 0; i < 5; i++) {
            if (playerQuests[i].getIfActive()) {
                hasQuests = true;
                cout << playerQuests[i].getName() << ": " << playerQuests[i].getDescription() << "." << endl;
            }
        }
        hasQuests = false;
        cout << "Your other quests are: " << endl;
        for (int i = 5; i < 10; i++) {
            if (playerQuests[i].getIfActive()) {
                hasQuests = true;
                cout << playerQuests[i].getName() << ": " << playerQuests[i].getDescription() <<  ". The reward is " << playerQuests[i].getReward().getName()  << "." << endl;
            }
        }
        if (!hasQuests) {
            cout << "You have no other quests active currently" << endl;
        }
        break;
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
            cout << "1. Buy bombs, increases your mining luck" << endl;
            cout << "2. Sell copper ore" << endl;
            cout << "3. Sell iron ore" << endl;
            cout << "4. Sell gold ore" << endl;
            cout << "5. Sell frozen tears" << endl;
            cout << "6. Sell emeralds" << endl;
            cout << "7. Sell diamonds" << endl;
            cout << "8. Exit" << endl;
            cout << "===========================" << endl;
            choice2 = promptInt(1,8);

            if (thePlayer.setTime()) {
                cout << "It got too late, you passed out" << endl;
                thePlayer.newDayOutside();
                return true;
            }

            switch(choice2) {
                case 1: {
                    buy(inventory,"Bomb", "Explosive device used in the mines",100);
                    break;
                }
                case 2: {
                    sell( inventory, "Copper Ore" , 10);
                    break;
                }

                case 3: {
                    sell(inventory,"Iron Ore",50);
                    break;
                }

                case 4: {
                    sell( inventory, "Gold Ore" , 75);
                    break;
                }

                case 5: {
                    sell(inventory,"Frozen Tear(s)",100);
                    break;
                }

                case 6: {
                    sell( inventory, "Emerald(s)" , 250);
                    break;
                }
                case 7: {
                  sell (inventory, "Diamond(s)", 800);
                  break;
                }
                case 8: {
                    exit = false;
                    break;
                }
            }
        }
        break;
      }

      case 7: {
        Mine(inventory);
        if (thePlayer.setTime()) {
          cout << "It got too late, you passed out" << endl;
          thePlayer.newDayOutside();
          return true;
        }
        break;
      }

      case 0: {
        return false;
        break;
      }
    }
  }
}


