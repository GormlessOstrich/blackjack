#include <iostream>
#include <vector> // Provides std::vector to allow for dynamically sized arrays.
#include <cstdlib> // The C standard library, for random number generation.
#include <ctime>

using namespace std; // Allows the use of standard library features without prefixing "std::".

int main() {
    srand(static_cast<unsigned int>(time(0))); /* This seeds the random number generator with the current time, ensuring different numbers each time the program runs.
    static_cast<unsigned int> is used to convert the time to an unsigned integer.
    */

    vector<int> deck = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}; // Card values.
    int playerTotal = 0;
    char choice;

    // Initial deal.
    playerTotal += deck[rand() % deck.size()]; // Ensures that the result is a number between 0 and 12 (inclusive).
    playerTotal += deck[rand() % deck.size()];

    cout << "Your total is: " << playerTotal << endl;

    // Player's turn.
    do { // A loop that continues until the player decides to stand.
        cout << "Will you hit (h) or stand (s)? ";
        cin >> choice;

        if (choice == 'h') {
            playerTotal += deck[rand() % deck.size()];
            cout << "Your total is: " << playerTotal << endl;
            if (playerTotal > 21) {
                cout << "You bust! Game over." << endl;
                return 0;
            }
        }
    } while (choice != 's'); // choice is not equal to s(tand).

    // Dealer's turn and further logic will follow here.

    return 0;
}