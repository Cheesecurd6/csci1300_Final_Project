#include <string>
#include <iostream>
#include "player.h"

    std::string Player::getLocation() const {
        return location;
    }
    std::string Player::getName() const {
        return name;
    }
    int Player::getDay() const {
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
    void Player::setDay(int playerDay) {
        day = playerDay;
    }
    void Player::setEnergy(int playerEnergy) {
        if (playerEnergy == 0) {
            std::cout << "You've run out of energy" << std::endl;
            newDay();
        }
        else {
            energy = playerEnergy;
        }
        energy = playerEnergy;
    }
    void Player::setJoja(int playerJoja) {
        joja = playerJoja;
    }

    bool Player::setTime() {
        time++;
        if (time == 5) {
            return newDay();
        }
        else {
            return false;
        }
    }

    void Player::setRealTime(int t) {
        time = t;
    }

    bool Player::newDay() {
        time = 0;
        day++;
        energy = 100;
        location = "Farm";
        return true;
    }

    int Player::getTime() {
        return time;
    }

    
