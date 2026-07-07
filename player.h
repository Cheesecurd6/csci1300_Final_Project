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

    void setLocation(std::string playerLocation);
    void newDay();
    void setTime();
    void setName();
    void setDay(int playerDay);
    void setEnergy(int playerEnergy);
    void setJoja(int playerJoja);

    
    private:
    std::string location;
    std::string name;
    int time;
    int day;
    int energy = 100;
    int joja;
};

#endif