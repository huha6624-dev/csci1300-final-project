#include "Rose.h"
#include <iostream>
using namespace std;

Rose::Rose() {
    thirst = 0;
    wiltLimit = 5;
}

void Rose::water() {
    thirst = 0;
    cout << "You water the Rose. She looks much happier." << endl;
}

void Rose::increaseThirst() {
    thirst++;
}

int Rose::getThirst() {
    return thirst;
}

bool Rose::isWilted() {
    return thirst >= wiltLimit;
}
