#ifndef ITEM_H
#define ITEM_H
#include <string>
class Item {
    private:
    std::string description;
    int amount;
    int value;
    std::string name;
    bool seed;

    public:
    std::string getDescription();
    int getAmount();
    int getValue();
    std::string getName();
    bool getSeed();

    Item(std::string d, int a, int v, std::string n, bool s);
    Item();
    void setAmount(int a);
};

#endif