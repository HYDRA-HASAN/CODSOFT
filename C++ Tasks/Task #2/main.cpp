#include<iostream>
using namespace std;

int main() {
    // Declaration of variables to store user input and choice
    int num_1, num_2, choice;

    // Prompting the user to enter the first number
    cout << "Enter First Number: ";
    cin >> num_1;

    // Prompting the user to enter the second number
    cout << "Enter Second Number: ";
    cin >> num_2;

    // Displaying the menu of operations for the user to select
    cout << "Select the operator:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;

    // Getting the choice of the user
    cin >> choice;

    // Performing the operation based on user's choice
    switch(choice) {
        case 1:
            // Addition
            cout << "Result: " << num_1 + num_2 << endl;
            break;
        case 2:
            // Subtraction
            cout << "Result: " << num_1 - num_2 << endl;
            break;
        case 3:
            // Multiplication
            cout << "Result: " << num_1 * num_2 << endl;
            break;
        case 4:
            // Division
            if (num_2 != 0) {
                cout << "Result: " << num_1 / num_2 << endl;
            } else {
                // Handling division by zero case
                cout << "Cannot divide by zero!" << endl;
            }
            break;
        case 5:
            // Modulus
            cout << "Result: " << num_1 % num_2 << endl;
            break;
        default:
            // Handling invalid choice
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}