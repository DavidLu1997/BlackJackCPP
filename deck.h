#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class deck {
public:
    deck();
    card draw();
    void shuffle();
private:
    vector<card> c;
};

deck::deck() {
    char s;
    card temp;

    s = 'S';
    temp.suit = s;
    for(int i = 1; i <= 13; i++) {
        temp.value = i;
        c.push_back(temp);
    }

    s = 'H';
    temp.suit = s;
    for(int i = 1; i <= 13; i++) {
        temp.value = i;
        c.push_back(temp);
    }

    s = 'D';
    temp.suit = s;
    for(int i = 1; i <= 13; i++) {
        temp.value = i;
        c.push_back(temp);
    }

    s = 'C';
    temp.suit = s;
    for(int i = 1; i <= 13; i++) {
        temp.value = i;
        c.push_back(temp);
    }

    shuffle();
}

card deck::draw() {
    card s = c.front();
    c.erase(c.begin());
    return s;
}

void deck::shuffle() {

    srand(time(NULL));

    int j;
    card t;
    for(int i = 51; i >= 1; i--) {
        j = rand() % (i+1);
        t = c[i];
        c[i] = c[j];
        c[j] = t;
    }
}

#endif
