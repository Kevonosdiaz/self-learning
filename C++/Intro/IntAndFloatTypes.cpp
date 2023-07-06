#include <iostream>
#include <limits.h>
#include <iomanip> // To use fixed, scientific, setprecision(int), etc.
using namespace std;

int main() {
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

    // Int Types
    cout << sizeof(short) << endl;          // 2 bytes
    cout << sizeof(int) << endl;            // 4 bytes
    cout << sizeof(long) << endl;           // 8 bytes

    // Float Types
    cout << sizeof(float) << endl;          // 4 bytes
    cout << sizeof(double) << endl;         // 8 bytes
    cout << sizeof(long double) << endl;    // 16 bytes

    float fvalue = 76.4;
    double dvalue = 12312.123456789;
    cout << fixed << dvalue << endl;
    cout << scientific << dvalue << endl;
    cout << setprecision(9) << fixed << dvalue << endl;
}