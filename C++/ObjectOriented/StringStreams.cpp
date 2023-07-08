#include <iostream>
#include <sstream>

using namespace std;

/*
 * A stringstream can be used to combine different types into a single string
 * Somewhat like a string builder from Java.
*/
int main() {
  string name = "Bob";
  int age = 32;

  stringstream ss;
  ss << "Name is: ";
  ss << name;
  ss << "; Age is: ";
  ss << age;

  string info = ss.str();
  cout << info << endl;

  return 0;
}