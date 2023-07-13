#include <iostream>
using namespace std;

class Animal {
  private: // We can hide and encapsulate some (ideally as many as possible) of these properties, and restrict access by designing limited public methods
    string name;
    int age;

  private: // We can organize our class with multiple sections of private/public
    // We don't need to make a getter private, but just for example
    string getName() { return name; } // We can make methods to reuse, but make them only accessible by other methods
  public:
    void speakName() {cout << "My name is " << getName() << endl;}
    Animal();
    Animal(string name, int age): name(name), age(age) {}
};

// A subclass extending the Animal superclass (inherits fields and methods)
class Cat: public Animal {
  public:
    void leap() { cout << "Cat leaping!" << endl; }
};

int main() {
  Animal someAnimal;
  someAnimal.speakName();
  // Cannot leap() since it is not specifically a Cat.

  Cat someCat;
  someCat.speakName(); // Same as someAnimal.speak()

  // A subclass of Cat could speak, leap, and do anything itself has
  return 0;
}