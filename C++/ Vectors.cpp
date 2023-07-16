#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> myVector = {1,2,3};
  for (int i : myVector) {
    cout << i << endl;
  }

  vector<string> stringVec = {"One", "Two", "Three", "Four", "Five"};
  // Using the range for loop
  for (string s : stringVec) {
    cout << s << endl;
  }
}