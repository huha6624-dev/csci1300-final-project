#include <iostream>
#include <vector>
#include "Planet.h"
#include "KingPlanet.h"
#include "BusinessmanPlanet.h"
#include "Prince.h"
#include "Rose.h"
using namespace std;

int main() {
    // Starter content for checkpoint 2; the full set of planets will
    // grow in later checkpoints.
    vector<Planet*> planets;
    planets.push_back(new KingPlanet());
    planets.push_back(new BusinessmanPlanet());

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
            for (int i = 0; i < (int)planets.size(); i++) {
                cout << (i + 1) << ". " << planets[i]->getName() << endl;
            }
            int pick;
            cin >> pick;
            if (pick >= 1 && pick <= (int)planets.size()) {
                prince.setCurrentPlanet(planets[pick - 1]->getName());
                planets[pick - 1]->visit();
            } else {
                cout << "That planet doesn't exist yet." << endl;
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

    for (int i = 0; i < (int)planets.size(); i++) {
        delete planets[i];
    }

    return 0;
}
