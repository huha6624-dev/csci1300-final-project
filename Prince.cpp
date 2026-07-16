#include "Prince.h"
#include <iostream>
using namespace std;

Prince::Prince(string homePlanet) {
    name = "The Little Prince";
    currentPlanet = homePlanet;
    stars = 0;
    daysRemaining = 15;
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

void Prince::addDays(int amount) {
    daysRemaining = daysRemaining + amount;
}

bool Prince::isOutOfTime() {
    return daysRemaining <= 0;
}

void Prince::displayStatus() {
    cout << name << " is currently on: " << currentPlanet << endl;
    cout << "Stars collected: " << stars << endl;
    cout << "Days remaining: " << daysRemaining << endl;
}
