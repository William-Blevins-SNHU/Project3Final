#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;
// Begin ItemTracker defenition
class ItemTracker {
private:
    // Declares map
    map<string, int> itemCounts;

public:
    // Define method to read file and add items to map
    void readInputFile(const string& filename) {
        // Opens file
        ifstream file("inventory.txt");
        if (!file.is_open()) {
            cerr << "Error: File '" << filename << "' not found." << endl;
            return;
        }

        string item;
        while (file >> item) {
            // Sets each item to lowercase
            transform(item.begin(), item.end(), item.begin(), ::tolower);
            // If item present, add to itemCounts
            if (itemCounts.find(item) != itemCounts.end()) {
                itemCounts[item]++;
            }
            else {
                itemCounts[item] = 1;
            }
        }
        // Closes file
        file.close();
    }
    // Defines method to search for items in map
    int findFrequency(const string& item) {
        // Force value passd to method tp lower to prevent case issues
        string itemLower = item;
        transform(itemLower.begin(), itemLower.end(), itemLower.begin(), ::tolower);
        // If item present return frequency
        if (itemCounts.find(itemLower) != itemCounts.end()) {
            return itemCounts[itemLower];
        }
        else {
            return 0;
        }
    }
    //Defines method to print frequencies
    void printItemFrequencies() {
        for (const auto& pair : itemCounts) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
    // Defines method to print asteriks for each occurence of an item
    void printHistogram() {
        // Itterates through itemCounts and prints the key
        for (const auto& pair : itemCounts) {
            cout << pair.first << " ";
            // Prints the same amount of asteriks as the value for each key-value pair
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};
