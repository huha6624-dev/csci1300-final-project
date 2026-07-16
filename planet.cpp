#include "planet.h"
#include <iostream>
using namespace std;

Planet::Planet(string n, string d) {
    name = n;
    description = d;
}

Planet::~Planet() {
    // Nothing to clean up; here so derived classes destruct safely.
}

string Planet::getName() {
    return name;
}

string Planet::getDescription() {
    return description;
}

void Planet::visit() {
    // Placeholder; overridden by specific planets.
    cout << description << endl;
    cout << "(Nothing to do here yet.)" << endl;
}