#ifndef PLANET_H
#define PLANET_H

#include <string>
using namespace std;

// Base class for every planet/asteroid the Prince can travel to.
// More planets (Vain Man, Drunkard, Lamplighter, Geographer, Earth,
// etc.) are planned to specialize this the same way KingPlanet and
// BusinessmanPlanet do below.
class Planet {
protected:
    string name;
    string description;

public:
    Planet(string n, string d);
    virtual ~Planet();

    string getName();
    string getDescription();

    // Placeholder for now; each derived planet will override this
    // with its own NPC dialogue and reward logic.
    virtual void visit();
};

#endif
