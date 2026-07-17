#include "planet.h"
#include <iostream>
using namespace std;

Planet::Planet(string n, string d, string q, string a, int reward, string shortcut) {
    name = n;
    description = d;
    question = q;
    answer = a;
    starReward = reward;
    shortcutLine = shortcut;
    shortcutDaysCost = 1;
    lastDaysCost = 0;
}

string Planet::getName() {
    return name;
}

string Planet::getDescription() {
    return description;
}

int Planet::askQuestion() {
    cout << question << endl;
    cout << "Your answer: ";
    string guess;
    getline(cin, guess);

    if (guess == answer) {
        cout << "Correct! You earn " << starReward << " star(s)." << endl;
        return starReward;
    } else {
        cout << "Not quite. The answer was: " << answer << endl;
        return 0;
    }
}

int Planet::offerShortcutOrQuestion() {
    cout << shortcutLine << endl;
    cout << endl;
    cout << "1. Answer the question honestly for " << starReward << " star(s)" << endl;
    cout << "2. Take the shortcut for " << starReward << " guaranteed star(s), but it costs "
         << shortcutDaysCost << " extra day(s)" << endl;
    cout << "Choose: ";

    string pickLine;
    getline(cin, pickLine);
    int pick = stoi(pickLine);

    if (pick == 2) {
        lastDaysCost = shortcutDaysCost;
        cout << "You take the shortcut. " << starReward << " star(s) earned, no questions asked." << endl;
        return starReward;
    } else {
        lastDaysCost = 0;
        return askQuestion();
    }
}

int Planet::getLastDaysCost() {
    return lastDaysCost;
}

int Planet::visit() {
    cout << description << endl;
    return offerShortcutOrQuestion();
}
