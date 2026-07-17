#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#include "planet.h"
#include "KingPlanet.h"
#include "BusinessmanPlanet.h"
#include "Prince.h"
#include "Rose.h"

int main() {
    // --- Load NPC/planet data from file (file I/O requirement) ---
    // Each line: name|description|question|answer|starReward|shortcutLine
    ifstream inFile("planets.txt");
    if (!inFile.is_open()) {
        cout << "Could not open planets.txt! Make sure it's in the same folder as the program." << endl;
        return 1;
    }

    vector<string> names;
    vector<string> descriptions;
    vector<string> questions;
    vector<string> answers;
    vector<int> rewards;
    vector<string> shortcuts;

    string n, d, q, a, rewardText, shortcutText;
    while (getline(inFile, n, '|') && getline(inFile, d, '|') && getline(inFile, q, '|') && getline(inFile, a, '|') && getline(inFile, rewardText, '|') && getline(inFile, shortcutText)) {
        names.push_back(n);
        descriptions.push_back(d);
        questions.push_back(q);
        answers.push_back(a);
        rewards.push_back(stoi(rewardText));
        shortcuts.push_back(shortcutText);
    }
    inFile.close();

    // We expect exactly 4 lines in planets.txt: King, Businessman,
    // Vain Man, Drunkard, in that order.
    if (names.size() < 4) {
        cout << "planets.txt is missing data. Expected 4 planet entries." << endl;
        return 1;
    }

    // --- Build each planet as its own named object (no pointers) ---
    KingPlanet king(names[0], descriptions[0], questions[0], answers[0], rewards[0], shortcuts[0]);
    BusinessmanPlanet businessman(names[1], descriptions[1], questions[1], answers[1], rewards[1], shortcuts[1]);
    Planet vainMan(names[2], descriptions[2], questions[2], answers[2], rewards[2], shortcuts[2]);
    Planet drunkard(names[3], descriptions[3], questions[3], answers[3], rewards[3], shortcuts[3]);

    // Menu display names only (vector of strings, matches taught vector usage).
    vector<string> planetNames;
    planetNames.push_back(king.getName());
    planetNames.push_back(businessman.getName());
    planetNames.push_back(vainMan.getName());
    planetNames.push_back(drunkard.getName());

    Prince prince("Asteroid B-612");
    Rose rose;

    int shortcutsTaken = 0;
    bool gameOver = false;
    bool gameWon = false;
    bool roseWilted = false;

    int choice = -1;

    cout << "=== The Little Prince ===" << endl;
    cout << "Collect 10 stars and bring them to the Snake on Earth before your days run out." << endl;

    while (!gameOver && choice != 0) {
        cout << endl;
        cout << "--- Day " << (8 - prince.getDaysRemaining() + 1) << " | Days left: " << prince.getDaysRemaining()
             << " | Stars: " << prince.getStars() << " | Water: " << prince.getWater()
             << " | Rose thirst: " << rose.getThirst() << " ---" << endl;
        cout << "1. Visit a planet" << endl;
        cout << "2. Water the rose" << endl;
        cout << "3. View status" << endl;
        cout << "4. View inventory" << endl;
        cout << "5. Travel to Earth and see the Snake" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter your choice: ";
        string choiceLine;
        getline(cin, choiceLine);
        choice = stoi(choiceLine);

        if (choice == 1) {
            cout << endl << "Which planet?" << endl;
            int total = planetNames.size();
            for (int i = 0; i < total; i++) {
                cout << (i + 1) << ". " << planetNames[i] << endl;
            }
            string pickLine;
            getline(cin, pickLine);
            int pick = stoi(pickLine);

            int earned = 0;
            int daysCost = 0;
            switch (pick) {
                case 1:
                    prince.setCurrentPlanet(king.getName());
                    earned = king.visit();
                    daysCost = king.getLastDaysCost();
                    break;
                case 2:
                    prince.setCurrentPlanet(businessman.getName());
                    earned = businessman.visit();
                    daysCost = businessman.getLastDaysCost();
                    break;
                case 3:
                    prince.setCurrentPlanet(vainMan.getName());
                    earned = vainMan.visit();
                    daysCost = vainMan.getLastDaysCost();
                    break;
                case 4:
                    prince.setCurrentPlanet(drunkard.getName());
                    earned = drunkard.visit();
                    daysCost = drunkard.getLastDaysCost();
                    break;
                default:
                    cout << "That planet doesn't exist yet." << endl;
                    break;
            }

            if (daysCost > 0) {
                prince.useDays(daysCost);
                shortcutsTaken++;
            }

            if (earned > 0) {
                prince.addStars(earned);
                prince.addItem("Star Charm from " + prince.getCurrentPlanet());
            }
            prince.useDay();
            rose.increaseThirst();
        } else if (choice == 2) {
            if (prince.useWater()) {
                rose.water();
                prince.useDay();
            } else {
                cout << "Your canteen is empty! You have no water left to give the Rose." << endl;
            }
        } else if (choice == 3) {
            cout << endl;
            prince.displayStatus();
            cout << "Rose thirst: " << rose.getThirst();
            if (rose.isWilted()) {
                cout << " (WILTED)";
            }
            cout << endl;
        } else if (choice == 4) {
            cout << endl;
            prince.displayInventory();
        } else if (choice == 5) {
            prince.useDay();
            rose.increaseThirst();
            if (prince.getStars() >= 10) {
                cout << endl << "You give your stars to the Snake." << endl;
                cout << "The Snake's bite sends you home, back to your Rose." << endl;
                gameWon = true;
                gameOver = true;
            } else {
                cout << endl << "The Snake says: \"You do not have enough stars yet.\"" << endl;
                cout << "You need " << (10 - prince.getStars()) << " more star(s)." << endl;
            }
        } else if (choice == 0) {
            cout << endl << "\"And now here is my secret, a very simple secret...\"" << endl;
            cout << "Goodbye." << endl;
        } else {
            cout << "That's not a valid option. Try again." << endl;
        }

        if (!gameOver && rose.isWilted()) {
            roseWilted = true;
            gameOver = true;
        }

        if (!gameOver && prince.isOutOfTime()) {
            gameOver = true;
        }
    }

    cout << endl << "==================================================" << endl;
    if (gameWon) {
        cout << "YOU WIN! The Prince returns home with " << prince.getStars() << " stars." << endl;
        if (shortcutsTaken > 0) {
            cout << "You leaned on a shortcut " << shortcutsTaken << " time(s) along the way, " << endl;
            cout << "but the stars you carry are no less real for it." << endl;
        } else {
            cout << "Every star was earned honestly, question by question." << endl;
        }
    } else if (gameOver && roseWilted) {
        cout << "GAME OVER: The Rose wilted from thirst while you were away." << endl;
        cout << "Final stars collected: " << prince.getStars() << " / 10" << endl;
    } else if (gameOver) {
        cout << "GAME OVER: The days ran out before the Prince reached the Snake." << endl;
        cout << "Final stars collected: " << prince.getStars() << " / 10" << endl;
    }
    cout << "==================================================" << endl;

    return 0;
}
