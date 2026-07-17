#ifndef KINGPLANET_H
#define KINGPLANET_H

#include "planet.h"

// A specific planet, home to the lonely King. Inherits the shared
// name/description/visit() interface from Planet and overrides
// visit() with the King's own dialogue and question.
class KingPlanet : public Planet {
private:
    bool questionAsked;

public:
    KingPlanet();

    void visit() override;
};

#endif
