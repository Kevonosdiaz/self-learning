#include <iostream>
using namespace std;

int main() {
    int values[3];
    values[0] = 1;
    values[1] = 2;
    values[2] = 3;
    // values[3] is some random garbage in memory.
    // Be careful with writing to areas outside of arrays!

    double numbers[4] = {1.2, 3.4, 5.6, 7.8};

    for (int i = 0; i < sizeof(numbers)/8; i++) {
        cout << "Number at position " << i << "= " << numbers[i] << endl;
    }

    string animals[][3] = {
        {"fox", "dog", "cat"},
        {"mouse", "squirrel", "parrot"}
    };
    // Strings are 8 bytes each, and we have 6 of them
    int subarrays = sizeof(animals)/sizeof(animals[0]); // 48/24

    int elements = sizeof(animals)/sizeof(animals[0][0]); // (48/8) 

    cout << "Subarrays in 'animals' = " << subarrays << ", total elements in 'animals' = " << elements << endl;

    return 0;
}