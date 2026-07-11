#include <string>
#include "Item.h"
#include <iostream>
using namespace std;

    std::string Item::getDescription() {
        return description;
    }
    int Item::getAmount() {
        return amount;
    }
    std::string Item::getName() {
        return name;
    }

    bool Item::getSeed() {
        return seed;
    }

    Item::Item(std::string d, int a, std::string n, bool s) {
        description = d;
        amount = a;
        name = n;
        seed = s;
    }
    Item::Item(std::string d) {
        name = d;
    }
    Item::Item() {
        description = " ";
        amount = 0;
        name = " ";
        seed = 0;
    }

    void Item::setAmount(int a) {
    amount += a;
    if (amount == 0) {
        description = " ";
        amount = 0;
        seed = 1;
    }
    }
