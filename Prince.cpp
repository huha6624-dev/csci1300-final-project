#include "Prince.h"
#include <iostream>
using namespace std;

Prince::Prince(string homePlanet) {
    name = "The Little Prince";
    currentPlanet = homePlanet;
    stars = 0;
    daysRemaining = 8;
    water = 5;
}

string Prince::getName() {
    return name;
}

string Prince::getCurrentPlanet() {
    return currentPlanet;
}

void Prince::setCurrentPlanet(string planetName) {
    currentPlanet = planetName;
}

int Prince::getStars() {
    return stars;
}

void Prince::addStars(int amount) {
    stars = stars + amount;
}

int Prince::getDaysRemaining() {
    return daysRemaining;
}

void Prince::useDay() {
    if (daysRemaining > 0) {
        daysRemaining--;
    }
}

void Prince::useDays(int amount) {
    daysRemaining = daysRemaining - amount;
    if (daysRemaining < 0) {
        daysRemaining = 0;
    }
}

bool Prince::isOutOfTime() {
    return daysRemaining <= 0;
}

int Prince::getWater() {
    return water;
}

bool Prince::useWater() {
    if (water > 0) {
        water--;
        return true;
    }
    return false;
}

void Prince::addItem(string item) {
    inventory.push_back(item);
}

void Prince::displayInventory() {
    cout << "Inventory:" << endl;
    if (inventory.empty()) {
        cout << "  (empty)" << endl;
        return;
    }
    int total = inventory.size();
    for (int i = 0; i < total; i++) {
        cout << "  " << (i + 1) << ". " << inventory[i] << endl;
    }
}

void Prince::displayStatus() {
    cout << name << " is currently on: " << currentPlanet << endl;
    cout << "Stars collected: " << stars << " / 10" << endl;
    cout << "Days remaining: " << daysRemaining << endl;
    cout << "Water remaining: " << water << endl;
}
