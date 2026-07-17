#include "BusinessmanPlanet.h"
#include <iostream>
using namespace std;

BusinessmanPlanet::BusinessmanPlanet(string n, string d, string q, string a, int reward)
    : Planet(n, d, q, a, reward) {
    starsForSale = 3;
    daysCost = 2;
    lastDaysCost = 0;
}

int BusinessmanPlanet::visit() {
    cout << description << endl;
    cout << "The Businessman says: \"Five hundred and one million...\"" << endl;
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

int BusinessmanPlanet::getLastDaysCost() {
    return lastDaysCost;
}
