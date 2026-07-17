#ifndef BUSINESSMANPLANET_H
#define BUSINESSMANPLANET_H

#include "planet.h"

// The Businessman offers a tradeoff: answer his question the honest
// way, or pay days off the Prince's remaining time for guaranteed
// stars. This is the game's JojaMart-style shortcut system.
class BusinessmanPlanet : public Planet {
private:
    int starsForSale;
    int daysCost;
    int lastDaysCost;   // days spent on the most recent visit's shortcut (0 if none)

public:
    BusinessmanPlanet(string n, string d, string q, string a, int reward);

    int visit() override;

    int getLastDaysCost();
};

#endif
