#include <iostream>
using namespace std;

int main() {
    cout << "Enter your name: " << flush;
    string input;
    cin >> input; // Store the user input into the variable input

    cout << "Hi " << input << "!" << endl;

    cout << "Enter a number: " << flush;
    int value;
    cin >> value;

    cout << "You entered: " << value << endl;
    return 0;
}