#include <iostream>
using namespace std;

/*
 * We can make function prototypes here, or even in a header file elsewhere (.h file)
 * We could #include "file.h" to incorporate all the function prototypes and any other code 
 * 
 * utils.h
 * 
 * #ifndef UTILS_H_
 * #define UTILS_H_
 * void processSelection(int selection);
 * void showMenu();
 * int getSelection();
 * #endif
*/


void showMenu() {

    cout << endl << "1. Search" << endl;
    cout << "2. View Record" << endl;
    cout << "3. Quit" << endl;

    // cout << "Enter selection > " << endl;
}

int getSelection() {
    cout << "Enter selection > " << endl;
    int input;
    cin >> input;

    return input;
    // Note we cannot return arrays directly (use pointers later on!)
}

void processSelection(int selection) {
    switch(selection) {
    case 1:
        cout << "Searching..." << endl;
        break;
    case 2:
        cout << "Viewing..." << endl;
        break;
    case 3:
        cout << "Quitting..." << endl;
        break;

    default:
        cout << "Please select an item from the menu." << endl;
        int input = getSelection();
        processSelection(input);
    }
}

int main() {
    showMenu();
    int input = getSelection();

    // Switch statement for different cases of input
}