#include <iostream>
#include <unordered_map>
// Incomplete solution
int main() {
    using namespace std;
    int n, divisor;

    // Parse the first line of input
    cin >> n;
    cin >> divisor;

    // Use a hashmap with the key being the quotient and the value being the numerator
    unordered_map<int, int> seen;
    int curr;

    // Everytime we have a collision (of keys), increment res
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        int quo = curr/divisor;
        if (seen.find(quo) == seen.end()) {
            // If not found, add it
            seen[curr] = quo;
        } else {
            res++;
        }
    }
    cout << res;
    return 0;
}