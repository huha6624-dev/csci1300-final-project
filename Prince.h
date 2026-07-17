#ifndef PRINCE_H
#define PRINCE_H

#include <string>
#include <vector>
using namespace std;

// The player character. Tracks where the Prince currently is, how
// many stars/items he has collected, his water canteen, and how many
// days he has left before time runs out.
class Prince {
private:
    string name;
    string currentPlanet;
    int stars;
    int daysRemaining;
    int water;
    vector<string> inventory;

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
    void useDays(int amount);
    bool isOutOfTime();

    int getWater();
    bool useWater();

    void addItem(string item);
    void displayInventory();

    // Prints the Prince's current stats to the console.
    void displayStatus();
};

#endif
