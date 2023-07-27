#include <iostream>
using namespace std;

void softDoubleIt(int value) {
    value = 2 * value;
}

// Use reference variables
void hardDoubleIt(int *valuePtr) {
    *valuePtr = 2 * *valuePtr;
}

int main() {
    int nValue = 5;

    int* pnValue = &nValue; // Create an integer ptr to the address of the int nValue, calling it pnValue

    cout << "Int value via ptr: " << *pnValue << endl; // Dereference the pointer, getting the value at the address 

    // Declare a pointer var : (type)*
    // Get the address       : &(var)
    // Dereference a ptr     : *(var)

    cout << "1. Original nValue: " << nValue << endl;
    softDoubleIt(nValue);
    cout << "2. Value after softDoubleIt: " << nValue << endl;
    hardDoubleIt(&nValue);
    cout << "3. Value after hardDoubleIt: " << nValue << endl;
}