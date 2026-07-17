#include "KingPlanet.h"
#include <iostream>
using namespace std;

KingPlanet::KingPlanet(string n, string d, string q, string a, int reward, string shortcut)
    : Planet(n, d, q, a, reward, shortcut) {
    questionAsked = false;
}

int KingPlanet::visit() {
    cout << description << endl;
    cout << "The King says: \"Ah, here is a subject!\"" << endl;
    questionAsked = true;
    return offerShortcutOrQuestion();
}
