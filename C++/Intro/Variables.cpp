#include <iostream> 
using namespace std;

int main() {
    int numberCats = 5;
    cout << "Number of cats: " << numberCats << endl;
    int catsAdded = 8;
    for (int i = 0; i < catsAdded; i++) {
        numberCats++;
    }
    cout << "New number of cats: " << numberCats << endl;
    return 0;
}