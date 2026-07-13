#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Mines.h"

using namespace std;

Mines::Mines(std::string n, std::vector<Villager> people) : Location(n,people){}

void Mines::Mine (Item inventory[], int bundleTracker[]) {
  int roll;
  std::mt19937 mt{std::random_device{}()};
  std::uniform_int_distribution<> d100{ 1, 100 };
  roll = d100(mt);

  if (roll >= 99) {
    cout << "\"You've freed me from my entrapment by that witch. As a reward I give you a mineral prized among you folk, a diamond.\"" << endl;
    if (addItem(inventory,Item ("Shiny shiny", 1, "Diamond", 0))) {
      cout << "\"Here you go!\"" << endl;
    }
    else {
      cout << "\"Oh no! It looks like you don't have any inventory space. Oh well I guess I can't give this to you after all.\"" << endl;
    }
  }
  else if (roll >= 90) {
    cout << "While splitting apart a particularly troublesome rock something green and very shiny pops out. It's an emerald!" << endl;
    if (addItem(inventory, Item("A lovely shade of green with an enchanting shimmer", 1, "Emerald",0))) {}
    else {
      cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
  }
  else if (roll >= 80) {
    cout << "On a very chilly level of the mines you stumble across a reflective blue mineral just laying on the ground. It's a frozen tear!" << endl;
    if (addItem(inventory, Item("A crystal teardrop rumored to be the result of a yeti crying", 1, "Frozen Tear", 0))){}
    else {
      cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
  }
  else if (roll >= 60) {
    cout << "You find a node of yellow shiny material and break it open inside you find something. It's gold ore!" << endl;
    if(addItem(inventory, Item("Very valuable and shiny", 1, "Gold Ore", 0))){}
    else {
      cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
  }
  else if (roll >= 30) {
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

bool Mines::mineTerminal(Player p, Item inventory[], Quest q[]) {
  thePlayer = p;
}


