#include <iostream>
#include "Validation.h"

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