#include <iostream> 
using namespace std;

int main() {
    int value = 5;

/*
* Break statement prevents "fall-through", used for most switch statements
*/
    switch(value) {
        case 1:
            cout << "Value is 1" << endl;
            break;
        case 2:
            cout << "Value is 2" << endl;
            break;
        case 3:
            cout << "Value is 3" << endl;
            break;
        case 4:
            cout << "Value is 4" << endl;
            break;
        case 5:
            cout << "Value is 5" << endl;
            break;
        default:
            cout << "Unrecognized value" << endl;
    }
    return 0;
}