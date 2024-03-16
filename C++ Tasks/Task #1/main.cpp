// NUMBER GUESSING GAME
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(nullptr));
    
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 10 + 1;
    
    // Initialize variables
    int guess;
    bool correct = false;
    
    // Game loop
    while (!correct) {
        // Ask the user to guess the number
        cout << "Guess a number between 1 and 10: ";
        cin >> guess;
        
        // Check if the guess is correct
        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the correct number.\n";
            correct = true;
        } else if (guess < randomNumber) {
            cout << "Too low. Try again.\n";
        } else {
            cout << "Too high. Try again.\n";
        }
    }
    
    return 0;
}