//TO-DO LIST 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <limits>

using namespace std;

// Define ANSI escape codes for text colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Function to read tasks from a file
vector<string> pullFile(const string& fileName) {
    vector<string> tasks;
    ifstream file(fileName);
    if (file.is_open()) {
        string task;
        while (getline(file, task)) {
            tasks.push_back(task);
        }
        file.close();
    }
    return tasks;
}

// Function to write tasks to a file
void pushFile(const vector<string>& totalList, const string& fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (const string& task : totalList) {
            file << task << endl;
        }
        file.close();
    }
}

// Function to check if a file exists
bool ifExists(const string& fileName) {
    ifstream file(fileName);
    return file.good();
}

// Function to print the task list
void printList(const vector<string>& totalList, const string& fileName) {
    cout << "Tasks in " << CYAN << fileName << RESET << ":\n"; // Color the file name
    for (size_t i = 0; i < totalList.size(); ++i) {
        cout << GREEN << (i + 1) << ". " << RESET << totalList[i] << "\n"; // Color the task numbers
    }
}

// Function to add a task with current date
void addTaskWithDate(vector<string>& totalList) {
    cout << "Enter new task: ";
    cin.ignore(); // Ignore the newline character in the buffer
    string task;
    getline(cin, task); // Allow input with spaces

    time_t now = time(0);
    tm* ltm = localtime(&now);

    stringstream ss;
    ss << "[" << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "] " << task;
    totalList.push_back(ss.str());
}

int main() {
    string fileName;
    vector<string> totalList;
    vector<string> names;

    // Load existing lists from a file
    if (ifExists("lists.txt")) {
        names = pullFile("lists.txt");
    }

    cout << "Available lists:\n";
    if (names.empty()) {
        cout << "No lists found.\n";
    } else {
        for (size_t i = 0; i < names.size(); ++i) {
            cout << YELLOW << (i + 1) << ". " << RESET << names[i] << "\n"; // Color the list numbers
        }
    }

    bool flag = true;
    while (flag) {
        cout << "\nEnter a new list name:\n>";
        cin >> fileName;
        cout << "\n";

        // Check if user entered a number corresponding to an existing list
        if (isdigit(fileName[0])) {
            int index = fileName[0] - '0';
            if (index > 0 && index <= names.size()) {
                fileName = names[index - 1];
                flag = false;
            } else {
                cout << RED << "Invalid list number.\n" << RESET; // Color the error message
            }
        } else {
            fileName += ".txt";
            names.push_back(fileName);
            flag = false;
        }
    }

    // Save updated list names
    pushFile(names, "lists.txt");

    // Load tasks from the selected list
    if (ifExists(fileName)) {
        totalList = pullFile(fileName);
    }

    bool cont = true;
    while (cont) {
        printList(totalList, fileName);
        int choice = 0;
        cout << "\nWhat would you like to do?\n";
        cout << YELLOW << "1. Add task\n";
        cout << "2. Remove task\n";
        cout << "3. Quit\n" << RESET;
        cin >> choice;
        cout << "\n";

        // Check for invalid input
        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid input. Please enter a valid choice: " << RESET;
            cin >> choice;
            cout << "\n";
        }

        if (choice == 1) {
            addTaskWithDate(totalList);
        } else if (choice == 2) {
            int itemNumber = 0;
            cout << "Enter task number to delete: ";
            cin >> itemNumber;
            cout << "\n";

            // Check for invalid task number
            while (cin.fail() || itemNumber < 1 || itemNumber > totalList.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << "Invalid task number. Please enter a valid task number: " << RESET;
                cin >> itemNumber;
                cout << "\n";
            }
            totalList.erase(totalList.begin() + (itemNumber - 1));
        } else if (choice == 3) {
            cont = false;
            pushFile(totalList, fileName);
            cout << "Exiting.\n";
        }
    }

    return 0;
}
