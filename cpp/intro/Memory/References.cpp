#include <iostream>
using namespace std;

int main() {
    int value1 = 1;

    int value2 = value1;
    int value2 = 2; // Overwrites the previous value of 1, from value1, since value2 does not reference value1

    int &value3 = value1; // Now references value1, linking to the exact same memory location as value1


    // Recall that we need to pass in a ptr into a function in order to save its result into a pre-existing variable
}