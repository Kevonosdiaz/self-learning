#include <iostream>
using namespace std;

int main() {
    string passwd;
    cin >> passwd;
    if (passwd == "MyPassword123") {
        cout << "Password accepted." << endl;
    }
    else {
        cout << "Password not accepted. Try again: " << endl;
    }

    cout << "1.\tAdd new record." << endl;
    cout << "2.\tDelete record." << endl;
    cout << "3.\tView record." << endl;
    cout << "4.\tSearch record." << endl;
    cout << "5.\tQuit." << endl;

    cout << "Enter your selection > " << flush;

    int selectionVal;
    cin >> selectionVal;

    if (selectionVal < 3) {
        cout << "These options are a work in progress, try again later." << endl;
    } else {
        cout << "These options are also a work in progress, try again later." << endl;
    }

    if (selectionVal == 5) {
        cout << "Quitting..." << endl;
    }
    
    return 0;
}