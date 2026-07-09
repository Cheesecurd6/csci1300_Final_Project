#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
    public:
    std::string getLocation() const;
    std::string getName() const;
    int getDay() const;
    int getEnergy() const;
    int getJojaInfluence() const;
    int getTime();
    int getGold();
    bool getIfDayPassed();

    void setLocation(std::string playerLocation);
    bool newDay();
    bool newDayOutside();
    bool setTime();
    void setRealTime(int t);
    void setName();
    void setDay(int playerDay);
    void setEnergy(int playerEnergy);
    void setJoja(int playerJoja);
    void setGold(int additionalGold);

    
    private:
    std::string location;
    std::string name;
    int time = 0;
    int day = 1;
    int energy = 100;
    int joja;
    int gold = 500;
    bool dayHasPassed = 0;
};

#endif