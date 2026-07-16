#include "KingPlanet.h"
#include <iostream>
using namespace std;

KingPlanet::KingPlanet()
    : Planet("The King's Planet", "A tiny planet ruled by a lonely king who claims to command everything, even the stars.") {
    questionAsked = false;
}

void KingPlanet::visit() {
    cout << description << endl;
    cout << "The King says: \"Ah, here is a subject!\"" << endl;
    cout << "(NPC question and star reward coming soon.)" << endl;
    questionAsked = true;
}
