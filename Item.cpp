#include <string>
#include "Item.hpp"

    std::string Item::getDescription() {
        return description;
    }
    int Item::getAmount() {
        return amount;
    }
    int Item::getValue() {
        return value;
    }
    std::string Item::getName() {
        return name;
    }

    bool Item::getSeed() {
        return seed;
    }

    Item::Item(std::string d, int a, int v, std::string n, bool s) {
        description = d;
        amount = a;
        value = v;
        name = n;
        seed = s;
    }
    Item::Item() {
        description = " ";
        amount = 0;
        value = 0;
        name = " ";
        seed = 0;
    }

    void Item::setAmount(int a) {
        amount += a;
    }
