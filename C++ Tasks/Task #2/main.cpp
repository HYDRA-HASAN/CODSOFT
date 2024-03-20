#include <iostream>
#include <iomanip> // for std::setw
#include <windows.h> // for console colors

using namespace std;

// Function to set text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    // Declaration of variables to store user input and choice
    int num_1, num_2, choice;

    // Prompting the user to enter the first number
    setColor(11); // Cyan color
    cout << "Enter First Number: ";
    setColor(15); // White color
    cin >> num_1;

    // Prompting the user to enter the second number
    setColor(11); // Cyan color
    cout << "Enter Second Number: ";
    setColor(15); // White color
    cin >> num_2;

    // Displaying the menu of operations for the user to select
    setColor(11); // Cyan color
    cout << "Select the operator:" << endl;
    cout << setw(5);
    setColor(14); // Yellow color
    cout << "1. Addition" << endl;
    cout << setw(5);
    setColor(14); // Yellow color
    cout << "2. Subtraction" << endl;
    cout << setw(5);
    setColor(14); // Yellow color
    cout << "3. Multiplication" << endl;
    cout << setw(5);
    setColor(14); // Yellow color
    cout << "4. Division" << endl;
    cout << setw(5);
    setColor(14); // Yellow color
    cout << "5. Modulus" << endl;

    // Getting the choice of the user
    setColor(15); // White color
    cin >> choice;

    // Performing the operation based on user's choice
    switch(choice) {
        case 1:
            // Addition
            setColor(10); // Green color
            cout << "Result: ";
            setColor(15); // White color
            cout << num_1;
            setColor(14); // Yellow color
            cout << " + ";
            setColor(15); // White color
            cout << num_2;
            setColor(14); // Yellow color
            cout << " = ";
            setColor(10); // Green color
            cout << num_1 + num_2 << endl;
            break;
        case 2:
            // Subtraction
            setColor(12); // Red color
            cout << "Result: ";
            setColor(15); // White color
            cout << num_1;
            setColor(14); // Yellow color
            cout << " - ";
            setColor(15); // White color
            cout << num_2;
            setColor(14); // Yellow color
            cout << " = ";
            setColor(12); // Red color
            cout << num_1 - num_2 << endl;
            break;
        case 3:
            // Multiplication
            setColor(14); // Yellow color
            cout << "Result: ";
            setColor(15); // White color
            cout << num_1;
            setColor(14); // Yellow color
            cout << " * ";
            setColor(15); // White color
            cout << num_2;
            setColor(14); // Yellow color
            cout << " = ";
            setColor(14); // Yellow color
            cout << num_1 * num_2 << endl;
            break;
        case 4:
            // Division
            if (num_2 != 0) {
                setColor(9); // Blue color
                cout << "Result: ";
                setColor(15); // White color
                cout << num_1;
                setColor(14); // Yellow color
                cout << " / ";
                setColor(15); // White color
                cout << num_2;
                setColor(14); // Yellow color
                cout << " = ";
                setColor(9); // Blue color
                cout << num_1 / num_2 << endl;
            } else {
                // Handling division by zero case
                setColor(12); // Red color
                cout << "Cannot divide by zero!" << endl;
            }
            break;
        case 5:
            // Modulus
            setColor(14); // Yellow color
            cout << "Result: ";
            setColor(15); // White color
            cout << num_1;
            setColor(14); // Yellow color
            cout << " % ";
            setColor(15); // White color
            cout << num_2;
            setColor(14); // Yellow color
            cout << " = ";
            setColor(14); // Yellow color
            cout << num_1 % num_2 << endl;
            break;
        default:
            // Handling invalid choice
            setColor(12); // Red color
            cout << "Invalid choice!" << endl;
            break;
    }

    setColor(7); // Reset to default color

    return 0;
}