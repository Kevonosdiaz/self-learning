#include <iostream>
#include <unordered_map>

int main() {
    using namespace std;
    int n, divisor, res = 0;

    // Parse the first line of input
    cin >> n;
    cin >> divisor;

    // Populate array with second line of input
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Natural idea: Check pairs between index i and every index j coming after it
    // Is this sufficiently fast though?
    for (int i = 0; i < n; i++) {
        int quo1 = arr[i]/divisor;
        for (int j = i+1; j < n; j++) {
            int quo2 = arr[j]/divisor;
            res += (quo1 == quo2);
        }
    }

    cout << res;
    return 0;
}