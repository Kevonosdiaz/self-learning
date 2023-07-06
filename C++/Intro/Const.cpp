#include <iostream>
using namespace std;

/*
 * Making values and even methods constant can be helpful for safety and ensuring everything works properly
 * Especially useful for use in classes and objects
*/
int main() {
    const double PI = 3.141592; // We can use const keyword to prevent changes, and the CAPITALIZED convention for constants

    // Applying const to a pointer's target (ex. const int *name) prevents changes writes to the value it points to (read-only access)
    // Applying const to a pointer directly (ex. int * const name) prevents changing the pointer (cannot point it elsewhere)
    // We can combine both of these (ex. const int * const name)

    return 0;
}