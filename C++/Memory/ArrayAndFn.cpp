#include <iostream>
using namespace std;

/**
 * Demonstrate passing in an array, as well as accepting the num of elements present in it (since we can't check from inside a fn)
 * The number of elements should be constant here, so const is used to enforce that, as good practice
 * 
 * We could also accept a string *ptr rather than an array[]
 * We could also replace both params with string (&texts)[3], but this looks a bit strange and appears less flexible.
*/
void showElements(const int NUM_ELEMENTS, string texts[]) {
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    cout << texts[i] << endl;
  }
}

string *getArray() {
  // string texts[] = {"one","two","three"};
  // return texts;     --- This would return a pointer to a pointer that points to nothing (local scope)

  // If we used the new keyword, we could return a pointer, just with the requirement of deleting it later
}

// Could make *get() and free(_ *ptr) memory functions

int main() {
  string texts[] = {"element1","element2","element3"};
  const int ELEMENTS = sizeof(texts)/sizeof(string);
  showElements(ELEMENTS, texts);

  return 0;
}