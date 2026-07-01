#include <string>
class Player {
    public:
    std::string getLocation() const;
    std::string getName() const;
    std::string getDay() const;
    int getEnergy() const;
    int getJojaInfluence() const;

    void setLocation(std::string playerLocation);
    void setName();
    void setDay(std::string playerDay);
    void setEnergy(int playerEnergy);
    void setJoja(int playerJoja);

    
    private:
    std::string location;
    std::string name;
    std::string day;
    int energy;
    int joja;
};