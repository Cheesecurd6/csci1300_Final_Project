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
    bool getBundle();
    bool getIfDayPassed();
    int getWeather();

    void setLocation(std::string playerLocation);
    bool setTime();
    void setRealTime(int t);
    void setName();
    void setDay(int playerDay);
    void setEnergy(int playerEnergy);
    void setJoja();
    void setGold(int additionalGold);
    void setIfDay();
    void setBundle(bool s);
    bool newDay();
    bool newDayOutside();

    
    private:
    std::string location;
    std::string name;
    int weather = 1;
    int time = 0;
    int day = 1;
    int energy = 100;
    int joja = 0;
    int gold = 500;
    bool dayHasPassed = 0;
    bool bundleDone = 0;

};

#endif