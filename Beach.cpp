#include <string>
#include <vector>
#include <random>
#include "Beach.h"
#include "Validation.h"

using namespace std;

Beach::Beach(std::string n, std::vector<Villager> people, int l) : Location(n,people,l){}

    void Beach::Fish (Item inventory[]) {
    bool found = false;
    bool found2 = false;
    int roll;
    int choice;
    int choice2;
    if (thePlayer.getWeather() == 2) {
        luck++;
    }
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<> d1000{ 1, 1000 };
    std::uniform_int_distribution<> weighted1000 {600,1000};
    std::uniform_int_distribution<> doubleWeighted1000 {750,1000};
    std::uniform_int_distribution<> tripleWeighted1000 {999,100};
    for (int i = 0; i < 10; i++) {
    if (inventory[i].getName() == "Bait") {
        if(inventory[i].getAmount() >= 0) {
            found = true;
        }
    }
    if (inventory[i].getName() == "Deluxe Bait") {
        if(inventory[i].getAmount() >= 0) {
            found2 = true;
        }
    }
    }
    if (found || found2) {
    cout << "===========================" << endl;
    cout << "Do you want to use bait?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "===========================" << endl;
    choice = promptInt(1,2);

    if (choice == 1) {
        cout << "===========================" << endl;
        cout << "What kind of bait?" << endl;
        if (found) {
            cout << "1. Normal Bait" << endl;
        }
        if (found2) {
            cout << "2. Deluxe Bait" << endl;
        }
        choice2 = promptInt(1,2);
        switch(choice2) {
            case 1: {
                if (searchPlayerInventory(Item("Just normal bait used to catch fish", 1 , "Bait", 5), inventory)) {
                    luck++;
                }
                break;
            }
            case 2: {
                if (searchPlayerInventory(Item("Deluxe bait attracting much rarer fish", 1 , "Deluxe Bait", 100), inventory)) {
                    luck+=3;
                }
                break;
            }
        }
    }
    }
    if (luck >= 3) {
        roll = tripleWeighted1000(mt);
    }
    else if (luck == 2) {
        roll = doubleWeighted1000(mt);
    }
    else if (luck == 1) {
        roll = weighted1000(mt);
    }
    else {
        roll = d1000(mt);
    }

    if (roll >= 999) {
        cout << "Something bites on the line and your forced to pull with all your might. Whatever the thing is it's very strong pulling this way and that. With a final heave you tear the thing out of the water. It's an octopus!" << endl;
        if (addItem(inventory,Item ("A mysterious creature from the depths of the ocean; delicious with a little lemona and salt", 1, "Octopus",0))) {}
    else {
        cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
    }
    else if (roll >= 750) {
        cout << "You catch something large on the line and immediatley reel it in. It's a Tilapia!" << endl;
        if (addItem(inventory, Item("A large and tasty fish", 1, "Tilapia",0))) {}
    else {
        cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
    }
    else if (roll >= 500) {
        cout << "You feel a familiar tugging on the line and start to pull up, a fish breaches the ocean surface. It's a Tuna!" << endl;
        if (addItem(inventory, Item("One of the more valuable fish in the sea", 1, "Tuna", 0))){}
    else {
        cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
    }
    else {
        cout << "You notice a pull on the line and drag whatever you caught up. It's a Sardine!" << endl;
        if(addItem(inventory, Item("Good for canning",1,"Sardine(s)",0))){}
    else {
        cout << "Unfortunately, you don't have enough inventory space and lose the item." << endl;
    }
    }
    
    luck = 0;
}
void Beach::buy(Item inventory[10], std::string name, std::string description, int price) {

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

void Beach::sell(Item inventory[10], std::string name, int value) {
    int amountSold;
    int index =-1;
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

bool Beach::addItem(Item inventory[10], Item questReward) {
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

    bool Beach::searchPlayerInventory(Item questItem, Item inventory[10]) {
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

void Beach::questCheck(int p, Quest playerQuests[], Item inventory[10]) {
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

    bool Beach::beachTerminal(Player p, Item inventory[], Quest playerQuests[], int bundleTracker[]) {
    thePlayer = p;
    while(true) {
        int choice;
        for (int i = 0; i < 10; i++) {
        if ((inventory[i].getName() == "Tuna") && (inventory[i].getAmount() >= 5)) {
            if (bundleTracker[3] <= 2) {
            bundleTracker[3] = 3;
            }
        }
        }
        cout << endl << endl;
        cout << "Day: " << thePlayer.getDay() << " Time: " << thePlayer.getTime() << endl;
        cout << "What would you like to do next? " << endl;
        //First menu
        cout << "===========================" << endl;
        cout << "1. Leave the " << getName() << endl;
        cout << "2. Talk to Willy" << endl;
        cout << "3. Check inventory" << endl;
        cout << "4. Check quests" << endl;
        cout << "5. Check map" << endl;
        cout << "6. Sell/Buy items from Willy" << endl;
        cout << "7. Go Fishing" << endl;
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
                cout << "Leaving the beach! Going to town." << endl;
                thePlayer.setLocation("Town");
                return true;
                break;
            }
            case 2: {
                int choice3;
                cout << "===========================" << endl;
                cout << "\"Oh hello there " << thePlayer.getName() << ", I'm " << getPeople()[0].getName() << " " << getPeople()[0].getDescription() << ", what can I do for you?\"" << endl;
                cout << "===========================" << endl;
                questCheck(0, playerQuests, inventory);
                if (bundleTracker[3] <= 3) {
                    bundleTracker[3] = 4;
                }

                cout << "===========================" << endl;
                cout << "1. \"What fish are there?\"" << endl;
                cout << "2. \"How can I fish for better fish?\"" << endl;
                cout << "3. \"How can I get an octopus?\"" << endl;
                cout << "===========================" << endl;
                choice3 = promptInt(1,3);
                switch (choice3) {
                    case 1:{
                    cout << "\"There's a lot of things you might pull out of the ocean." << endl;
                    cout << "Sardines are the most common fish you'll find." << endl;
                    cout << "Tuna are also pretty easy to come by." << endl;
                    cout << "Tilapia are harder to catch." << endl;
                    cout << "However, the rarest thing to find is definitely octopuses, in my whole time here I've only caught one." << endl;
                    cout << "If you're interested in catching one come to me and I'll show you how to do it.\"" << endl;
                    break;
                    }
                    case 2:{
                    cout << "\"To fish for better fish you should either fish while it's raining, or buy bait from me and use that when fishing." << endl;
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
                            cout << "\"If you want an octopus your gonna need the right bait, the normal bait I sell isn't going to cut it. Deluxe bait is what you need. Unfortunately, my supply has been cut off by that Joja man and his goons. Go fish up 5 tuna and I'll be able to make the bait.\"" << endl;
                            for (int i = 0; i < 10; i++) {
                                if (playerQuests[i].getName() == getPeople()[0].getQuest()) {
                                    playerQuests[i].setIfActive(1);
                                } 
                            }
                            if (bundleTracker[3] <= 1) {
                                bundleTracker[3] = 2;
                            }
                        }
                        else if (!isCompleted && isActive) {
                            cout << "\"By doing the taks I have you earlier.\"" << endl;
                        }
                        else if(isCompleted) {
                            cout << "\"I can't help you with that. I'm sorry lad I'm kind of busy right now and can't help you make more deluxe bait.\"" << endl;
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
                    cout << "1. Buy bait, increases your fishing luck" << endl;
                    cout << "2. Sell sardines" << endl;
                    cout << "3. Sell tuna" << endl;
                    cout << "4. Sell tilapia" << endl;
                    cout << "5. Sell octopus" << endl;
                    cout << "6. Exit" << endl;
                    cout << "===========================" << endl;
                    choice2 = promptInt(1,6);

                    if (thePlayer.setTime()) {
                        cout << "It got too late, you passed out" << endl;
                        thePlayer.newDayOutside();
                        return true;
                    }

                    switch(choice2) {
                        case 1: {
                            buy(inventory,"Bait", "Just normal bait used to catch fish",10);
                            break;
                        }
                        case 2: {
                            sell( inventory, "Sardine(s)" , 10);
                            break;
                        }

                        case 3: {
                            sell(inventory,"Tuna",50);
                            break;
                        }

                        case 4: {
                            sell( inventory, "Tilapia" , 100);
                            break;
                        }

                        case 5: {
                            sell(inventory,"Octopus",500);
                            break;
                        }
                        case 6: {
                            exit = false;
                            break;
                        }
                    }
                }
                break;
            }
            case 7: {
                Fish(inventory);
                break;
            }
            case 0: {
                return false;
                break;
            }
        }
    }
    }