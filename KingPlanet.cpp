#include "KingPlanet.h"
#include <iostream>
using namespace std;

KingPlanet::KingPlanet(string n, string d, string q, string a, int reward)
    : Planet(n, d, q, a, reward) {
    questionAsked = false;
}

int KingPlanet::visit() {
    cout << description << endl;
    cout << "The King says: \"Ah, here is a subject!\"" << endl;
    questionAsked = true;
    return askQuestion();
}
