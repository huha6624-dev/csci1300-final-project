#ifndef BUSINESSMANPLANET_H
#define BUSINESSMANPLANET_H

#include "planet.h"

// The Businessman offers his own, bigger version of the shortcut:
// more stars for more days than the other planets' shortcut. This is
// the game's JojaMart-style shortcut system.
class BusinessmanPlanet : public Planet {
private:
    int starsForSale;
    int daysCost;

public:
    BusinessmanPlanet(string n, string d, string q, string a, int reward, string shortcut);

    int visit() override;
};

#endif
