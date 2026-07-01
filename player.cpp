#include <string>
#include <iostream>
#include "player.hpp"

    std::string Player::getLocation() const {
        return location;
    }
    std::string Player::getName() const {
        return name;
    }
    std::string Player::getDay() const {
        return day;
    }
    int Player::getEnergy() const {
        return energy;
    }
    int Player::getJojaInfluence() const {
        return joja;
    }

    void Player::setLocation(std::string playerLocation) {
        location = playerLocation;
    }
    void Player::setName() {
        std::cout << "What's your name? ";
        getline(std::cin , name);
    }
    void Player::setDay(std::string playerDay) {
        day = playerDay;
    }
    void Player::setEnergy(int playerEnergy) {
        energy = playerEnergy;
    }
    void Player::setJoja(int playerJoja) {
        joja = playerJoja;
    }

    
