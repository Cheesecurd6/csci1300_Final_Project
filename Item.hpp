#ifndef ITEM_H
#define ITEM_H
#include <string>
class Item {
    private:
    std::string description;
    int amount;
    int value;
    std::string name;

    public:
    std::string getDescription();
    int getAmount();
    int getValue();
    std::string getName();

    Item(std::string d, int a, int v, std::string n);
    Item();
    int setAmount(int a);
};

#endif