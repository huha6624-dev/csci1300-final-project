#include <iostream>
#include <vector>
#include <string>
#include "planet.h"
#include "KingPlanet.h"
#include "Prince.h"
#include "Rose.h"
using namespace std;

int main() {
    // Each planet is its own named object, created directly (no
    // pointers, no "new"), the same way we've created objects like
    // "Villager Tony;" in class.
    KingPlanet king;

    // The Businessman doesn't have his own subclass yet; for now he's
    // just a plain Planet and will get his own quest logic (and
    // possibly his own subclass) in a later checkpoint.
    Planet businessman("The Businessman's Planet", "A planet occupied by a busy man who is endlessly counting the stars he says he owns.");

    // A vector of strings just to hold the menu display names, in
    // menu order. The planet objects themselves stay as their own
    // separate named variables above.
    vector<string> planetNames;
    planetNames.push_back(king.getName());
    planetNames.push_back(businessman.getName());

    Prince prince("Asteroid B-612");
    Rose rose;

    int choice = -1;

    cout << "=== The Little Prince ===" << endl;

    while (choice != 0) {
        cout << endl;
        cout << "--- Main Menu ---" << endl;
        cout << "1. Visit a planet" << endl;
        cout << "2. Water the rose" << endl;
        cout << "3. View status" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << endl << "Which planet?" << endl;
            int total = planetNames.size();
            for (int i = 0; i < total; i++) {
                cout << (i + 1) << ". " << planetNames[i] << endl;
            }
            int pick;
            cin >> pick;

            // Switch on the pick to call visit() on the matching
            // named object directly (dot notation, not "->").
            switch (pick) {
                case 1:
                    prince.setCurrentPlanet(king.getName());
                    king.visit();
                    break;
                case 2:
                    prince.setCurrentPlanet(businessman.getName());
                    businessman.visit();
                    break;
                default:
                    cout << "That planet doesn't exist yet." << endl;
                    break;
            }
        } else if (choice == 2) {
            rose.water();
        } else if (choice == 3) {
            cout << endl << "Current planet: " << prince.getCurrentPlanet() << endl;
            cout << "Stars: " << prince.getStars() << endl;
            cout << "Rose thirst: " << rose.getThirst() << endl;
        } else if (choice == 0) {
            cout << endl << "\"And now here is my secret, a very simple secret...\"" << endl;
            cout << "Goodbye." << endl;
        } else {
            cout << "That's not a valid option. Try again." << endl;
        }
    }

    return 0;
}
