#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "location.hpp"
using namespace std;

int main() {
    Player main;
    Location farm;
    std::string farmName;

    std::cout << "Welcome to my final project" << std::endl << std::endl << std::endl;
    main.setName();

    std::cout << "What's the name of you farm? ";
    getline(std::cin , farmName);
    farm.setName(farmName);
    main.setLocation(farm.getName());

    cout << "Hi " << main.getName() << " you're currently at " << main.getLocation() << endl;




}   