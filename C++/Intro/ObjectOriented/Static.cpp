#include <iostream>
using namespace std;

class Test {
  private:
    int id; // Non-static unique identifier for an object
    static int count;
  public:
    static int const MAX = 99; // Must initialize the CONST right here

    Test() {
      // Use prefix increment to start id at 1, rather than 0
      id = ++count; // We can keep track of the number of object instances using the static int count
    }
    ~Test() {
      count--;
    }

    static void showInfo() {
      cout << count << endl;  
    }
};

int Test::count = 0; // We must initialize the static var here

int main() {
  Test::showInfo();
  Test test1;

  Test::showInfo();
  Test test2;

  Test::showInfo();
  return 0;
}