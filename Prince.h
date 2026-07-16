#ifndef PRINCE_H
#define PRINCE_H

#include <string>
using namespace std;

// The player character. Tracks where the Prince currently is, how
// many stars he has collected, and how many days he has left before
// the Rose withers.
class Prince {
private:
    string name;
    string currentPlanet;
    int stars;
    int daysRemaining;

public:
    // homePlanet is the Prince's starting location (his own asteroid).
    Prince(string homePlanet);

    string getName();

    string getCurrentPlanet();
    void setCurrentPlanet(string planetName);

    int getStars();
    void addStars(int amount);

    int getDaysRemaining();
    void useDay();
    void addDays(int amount);

    bool isOutOfTime();

    // Prints the Prince's current stats to the console.
    void displayStatus();
};

#endif
