#include <iostream>
#include "deck.h"
#include "card.h"
#include <cstdio>
using namespace std;

void onePlayer();
void twoPlayer();

int softValue(vector<card> c);
int hardValue(vector<card> c);
int maxValue(vector<card> c);

int main()
{
    int choice = -1;
    while(choice != 0) {
        cout << "Welcome to BlackJack!" << endl;
        cout << "1. One Player" << endl;
        cout << "2. Two Players" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch(choice) {
        case 1:
            onePlayer();
            break;
        case 2:
            twoPlayer();
            break;
        default:
            return 0;
        }
    }

    return 0;
}

void onePlayer() {
    vector<card> player, dealer;
    deck d;

    //Deal two
    player.push_back(d.draw());
    dealer.push_back(d.draw());
    player.push_back(d.draw());
    dealer.push_back(d.draw());

    //Player's turn
    int choice = -1;
    cout << "Your cards: ";
    for(int i = 0; i < player.size(); i++) {
        cout << player[i].toString() << " ";
    }
    cout << endl;
    do {
        cout << "Would you like to: " << endl;
        cout << "1. Draw another card" << endl;
        cout << "2. Keep what you have" << endl;
        cout << "0. Exit the game" << endl;
        cin >> choice;

        switch(choice) {
        case 1:
            player.push_back(d.draw());
            cout << "Your cards: ";
            for(int i = 0; i < player.size(); i++) {
                cout << player[i].toString() << " ";
            }
            cout << endl;
            break;
        case 2:
            break;
        case 0:
            return;
        }
    }while(choice != 0 && choice != 2 && hardValue(player) < 21);

    if(maxValue(player) == 21) {
        cout << "You win!" << endl;
    }

    else if(hardValue(player) > 21) {
        cout << "You lose!" << endl;
    }

    else {
        cout << "Dealer's cards: ";
        for(int i = 0; i < dealer.size(); i++) {
            cout << dealer[i].toString() << " ";
        }
        cout << endl;
        while(hardValue(dealer) < 17 || softValue(dealer) == 17) {
            cout << "The dealer draws another card." << endl;
            dealer.push_back(d.draw());
            cout << "Dealer's cards: ";
            for(int i = 0; i < dealer.size(); i++) {
                cout << dealer[i].toString() << " ";
            }
            cout << endl;
            system("pause");
        }

        if((maxValue(player) > maxValue(dealer) && maxValue(dealer) < 21) || hardValue(dealer) > 21) {
            cout << "You win!" << endl;
        }

        else if(maxValue(player) == maxValue(dealer)) {
            cout << "You tie!" << endl;
        }

        else {
            cout << "You lose!" << endl;
        }
    }

    system("pause");
}

int softValue(vector<card> c) {
    int value = 0;

    for(int i = 0; i < c.size(); i++) {
        if(c[i].value == 1)
            value += 11;
        else if(c[i].value > 1 && c[i].value < 10)
            value += c[i].value;
        else
            value += 10;
    }

    return value;
}

int hardValue(vector<card> c) {
    int value = 0;

    for(int i = 0; i < c.size(); i++) {
        if(c[i].value == 1)
            value += 1;
        else if(c[i].value > 1 && c[i].value < 10)
            value += c[i].value;
        else
            value += 10;
    }

    return value;
}

int maxValue(vector<card> c) {
    int value = softValue(c);

    if(value > 21) {
        int aces = 0;
        for(int i = 0; i < c.size(); i++)
            if(c[i].value == 1)
                aces++;
        while(value > 21 && aces > 0) {
            aces--;
            value -= 10;
        }
    }

    return value;
}

void twoPlayer() {

}
