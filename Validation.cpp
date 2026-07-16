#include <iostream>
#include "Validation.h"

// Makes sure a valid input is entered so the program does not crash
string promptString() {
    string validation;
    getline(cin,validation);
    return validation;
}

int promptInt (int minVal, int maxVal) {
    int finalValue;
    while (true) {
        string input = promptString();
        try {
            finalValue = stoi(input);
        
        if (finalValue >= minVal && finalValue <= maxVal) {
            return finalValue;
        }
        } 
    catch (...) {
    }
    }
}