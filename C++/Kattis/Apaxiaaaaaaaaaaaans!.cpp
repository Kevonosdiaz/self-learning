#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string iName;
    cin >> iName;
    
    char old = 'A';
    stringstream ss;

    for (int i = 0; i < iName.length(); i++) {
        char current = iName[i];
        if (current != old) {
            ss << current;
        }
        old = current;
    }
    
    string oName = ss.str();
    cout << oName << endl;

    return 0;
}