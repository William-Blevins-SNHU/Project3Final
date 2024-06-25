#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "ItemTracker.h"

using namespace std;

int main() {
    // Creates tracker object
    ItemTracker tracker;
    // Feeds tracker object file
    tracker.readInputFile("inventory.txt");
    // Creates while loop variable
    int choice;
    string item;
    // Starts user menu while loop, accepts user input and reprompts until user
    // provides exit character
    while (true) {
        cout << "\nMenu Options:\n";
        cout << "1. Find frequency of a specific item.\n";
        cout << "2. Print item frequencies.\n";
        cout << "3. Print item frequencies as histogram.\n";
        cout << "4. Exit.\n";
        cout << "Enter your choice (1-4): ";

        // Checks users input and if not of expected type, output error and reprompt
        // user for input.
        if (!(cin >> choice)) {
            cout << "\nINVALID INPUT! Please enter a valid integer from 1-4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n');  // Ignore invalid input
            continue;
        }

        // Creates user options
        if (choice == 1) {
            cout << "Enter item to find frequency: ";
            cin >> item;
            // If item not found, output not found message and reprompt.
            if (tracker.findFrequency(item) == 0) {
                cout << "\nITEM DOES NOT APPEAR IN LIST\n";
                continue;
            }
            // Prints instances of provided items
            cout << "Frequency of '" << item << "': " << tracker.findFrequency(item)
                << endl;

        }
        else if (choice == 2) {
            cout << "\nItem frequencies:\n";
            // Prints how many times each item occurs
            tracker.printItemFrequencies();
        }
        else if (choice == 3) {
            cout << "\nHistogram:\n";
            // Prints occurences as a histogram
            tracker.printHistogram();
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
            return 0;
        }
        else {
            // Handles numeric input not in valid range, outputs error message and
            // reprompts user if input not from 1-4.
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue;
        }
    }

    return 0;
}
