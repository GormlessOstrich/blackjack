#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    // Card values
    vector<int> deck = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}; // 10 for J, Q, K and 11 for Ace
    int playerTotal = 0;
    char choice;

    // Initial deal
    playerTotal += deck[rand() % deck.size()];
    playerTotal += deck[rand() % deck.size()];

    cout << "Your total is: " << playerTotal << endl;

    // Player's turn
    do {
        cout << "Do you want to hit (h) or stand (s)? ";
        cin >> choice;

        if (choice == 'h') {
            playerTotal += deck[rand() % deck.size()];
            cout << "Your total is: " << playerTotal << endl;
            if (playerTotal > 21) {
                cout << "You bust! Game over." << endl;
                return 0;
            }
        }
    } while (choice != 's');

    // Dealer's turn and game logic would go here

    return 0;
}