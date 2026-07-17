#ifndef KINGPLANET_H
#define KINGPLANET_H

#include "planet.h"

// A specific planet, home to the lonely King. Inherits the shared
// name/description/question interface from Planet and overrides
// visit() with the King's own dialogue before asking his question.
class KingPlanet : public Planet {
private:
    bool questionAsked;

public:
    KingPlanet(string n, string d, string q, string a, int reward);

    int visit() override;
};

#endif
