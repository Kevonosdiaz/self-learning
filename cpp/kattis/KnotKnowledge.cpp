#include <iostream>
#include <unordered_set>

int main() {
    using namespace std;
    int count;
    cin >> count;

    // Initialize array of size count and populate it
    int required[count];
    unordered_set<int> seen;
    int curr;

    // Populate our list of required knots
    for (int i = 0; i < count; i++) {
        cin >> curr;
        required[i] = curr;
    }
    
    //cin >> curr; // Remove the \n

    // Populate a list of what has been learned
    for (int i = 0; i < count-1; i++) {
        cin >> curr;
        seen.emplace(curr);
    }

    // Check whether the required knots are in 'seen' or not
    for (int i = 0; i < count; i++) {
        // If not found
        if (seen.find(required[i]) == seen.end()) {
            cout << required[i];
            return 0;
        }
    }
    
    cout << '0';
    return 0;
}