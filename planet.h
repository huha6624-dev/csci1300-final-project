#ifndef PLANET_H
#define PLANET_H

#include <string>
using namespace std;

// Base class for every planet/asteroid the Prince can travel to.
// Each planet has a name/description, an NPC comp-sci question, and
// a shortcut line offering a guaranteed reward at the cost of extra
// days. visit() returns how many stars were earned on that visit.
class Planet {
protected:
    string name;
    string description;
    string question;
    string answer;
    int starReward;
    string shortcutLine;
    int shortcutDaysCost;
    int lastDaysCost;   // days spent on the most recent visit's shortcut (0 if none)

public:
    Planet(string n, string d, string q, string a, int reward, string shortcut);

    string getName();
    string getDescription();

    // Prints the NPC's question, reads the Prince's guess, and
    // returns the stars earned (starReward if correct, 0 if not).
    int askQuestion();

    // Offers the choice between answering honestly or taking the
    // shortcut for a guaranteed reward at the cost of extra days.
    // Shared by every planet, including derived ones.
    int offerShortcutOrQuestion();

    int getLastDaysCost();

    // Default visit: show the description, then offer the shortcut
    // or question. Derived planets override this to add their own
    // dialogue before doing the same thing.
    virtual int visit();
};

#endif
