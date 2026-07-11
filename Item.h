#ifndef ITEM_H
#define ITEM_H
#include <string>
class Item {
    private:
    std::string description;
    int amount;
    std::string name;
    bool seed;

    public:
    std::string getDescription();
    int getAmount();
    std::string getName();
    bool getSeed();

    Item(std::string d, int a, std::string n, bool s);
    Item(std::string d);
    Item();
    void setAmount(int a);
};

#endif