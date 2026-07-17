#ifndef PLANET_H
#define PLANET_H

#include <string>
using namespace std;

// Base class for every planet/asteroid the Prince can travel to.
// Each planet has a name/description, and an NPC comp-sci question
// the Prince can answer for stars. visit() returns how many stars
// were earned on that visit (0 if the question was missed).
class Planet {
protected:
    string name;
    string description;
    string question;
    string answer;
    int starReward;

public:
    Planet(string n, string d, string q, string a, int reward);

    string getName();
    string getDescription();

    // Prints the NPC's question, reads the Prince's guess, and
    // returns the stars earned (starReward if correct, 0 if not).
    // Shared by every planet, including derived ones.
    int askQuestion();

    // Default visit: show the description, then ask the question.
    // Derived planets override this to add their own dialogue.
    virtual int visit();
};

#endif
