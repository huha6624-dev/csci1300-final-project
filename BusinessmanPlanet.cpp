#include "BusinessmanPlanet.h"
#include <iostream>
using namespace std;

BusinessmanPlanet::BusinessmanPlanet(string n, string d, string q, string a, int reward, string shortcut)
    : Planet(n, d, q, a, reward, shortcut) {
    starsForSale = 3;
    daysCost = 2;
}

int BusinessmanPlanet::visit() {
    cout << description << endl;
    cout << shortcutLine << endl;
    cout << endl;
    cout << "1. Answer his question honestly for " << starReward << " star(s)" << endl;
    cout << "2. Buy " << starsForSale << " stars for " << daysCost << " days (shortcut)" << endl;
    cout << "Choose: ";

    string pickLine;
    getline(cin, pickLine);
    int pick = stoi(pickLine);

    if (pick == 2) {
        lastDaysCost = daysCost;
        cout << "You bought " << starsForSale << " stars from the Businessman." << endl;
        cout << "(The Businessman's influence over the stars grows a little more.)" << endl;
        return starsForSale;
    } else {
        lastDaysCost = 0;
        return askQuestion();
    }
}
