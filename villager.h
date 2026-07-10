#ifndef VILLAGER_H
#define VILLAGER_H
#include <iostream>
class Villager {
    public:
    Villager(std::string d,std::string n,std::string q);
    std::string getDescription() const;
    std::string getName() const;
    std::string getQuest() const;
    bool getQuestResult() const;

    void setDescription(std::string vDescription);
    void setName(std::string vName);
    void setQuest(std::string vQuest);
    void setQuestResult(bool result);

    private:
    std::string description;
    std::string name;
    std::string quest;
    bool questResult;
};

#endif