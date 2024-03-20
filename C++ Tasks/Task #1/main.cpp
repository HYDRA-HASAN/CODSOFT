#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ANSI escape codes for text colors
const string ANSI_RESET = "\033[0m";
const string ANSI_RED = "\033[31m";
const string ANSI_GREEN = "\033[32m";

int main() {
    // Seed the random number generator
    srand(time(nullptr));
    
    // Initialize variables
    char playAgain;
    bool correct = false;
    
    do {
        // Generate a random number between 1 and 10
        int randomNumber = rand() % 10 + 1;
        
        // Game loop
        while (!correct) {
            // Ask the user to guess the number
            cout << "Guess a number between 1 and 10: ";
            int guess;
            cin >> guess;
            
            // Check if the guess is correct
            if (guess == randomNumber) {
                cout << ANSI_GREEN << "Congratulations! You guessed the correct number." << ANSI_RESET << endl;
                correct = true;
            } else if (guess < randomNumber) {
                cout << ANSI_RED << "Too low. Try again." << ANSI_RESET << endl;
            } else {
                cout << ANSI_RED << "Too high. Try again." << ANSI_RESET << endl;
            }
        }

        // Ask if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        playAgain = tolower(playAgain);

        // Reset game state
        correct = false;

    } while (playAgain == 'y');

    cout << "Thanks for playing! Goodbye." << endl;
    
    return 0;
}