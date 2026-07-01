#include <string>
#include <vector>

class Location {
    public:
    std::string getName() const;
    void getPeople() const;
    void getNeighboringLocations() const;

    void setPeople(std::vector<std::string> locationPeople);
    void setName(std::string locationName);
    void setNeighbors(std::vector<Location> nearbyLocations);
    
    private:
    std::vector<std::string> people;
    std::string name;
    std::vector<Location> neighbors;
};