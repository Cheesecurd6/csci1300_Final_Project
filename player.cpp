#include <string>
#include <iostream>
#include <random>
#include "player.h"
#include "Validation.h"

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
        name = promptString();
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
    }
    void Player::setJoja() {
        joja++;
    }

    bool Player::setTime() {
        time++;
        return time == 20;
    }

    void Player::setRealTime(int t) {
        time = t;
    }

    bool Player::newDay() {
        // Rests the player and brings them back to the farm
        time = 0;
        day++;
        energy = 100;
        location = "Farm";
        // Rolls to see what the weather is today
        std::mt19937 mt{std::random_device{}()};
        std::uniform_int_distribution<> d3{ 1, 3 };
        weather = d3(mt);
        return true;
    }

    bool Player::newDayOutside() {
        // Tracks if a day has passed outside
        dayHasPassed = 1;
        location = "Farm";
        return true;
    }

    int Player::getTime() {
        return time;
    }

    bool Player::getIfDayPassed() {
        return dayHasPassed;
    }

    void Player::setIfDay() {
        // Resets so no day has passed outside
        dayHasPassed = 0;
    }

    int Player::getGold() {
        return gold;
    }

    void Player::setGold(int additionalGold) {
        gold+=additionalGold;
    }

    bool Player::getBundle() {
        return bundleDone;
    }
    void Player::setBundle(bool s) {
        bundleDone = s;
    }
    
    int Player::getWeather() {
        return weather;
    }
