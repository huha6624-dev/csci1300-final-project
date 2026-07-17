#include "planet.h"
#include <iostream>
using namespace std;

Planet::Planet(string n, string d, string q, string a, int reward) {
    name = n;
    description = d;
    question = q;
    answer = a;
    starReward = reward;
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

int Planet::visit() {
    cout << description << endl;
    return askQuestion();
}
