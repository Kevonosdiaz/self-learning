#include <iostream>
using namespace std;

class Cat {
public:
    Cat(); // Constructor
    Cat(string name, int age); // Overloading constructor to allow for including name and age;
    ~Cat(); // Destructor
    void speak();
    void setName(string name);
    string getName();
private:
    bool happy;
    string name;
    int age;
};

// Default cons using initialization list
Cat::Cat(): name("unnamed"), age(0), happy(true) {
  cout << "Cat created with defaults initialized." << endl;
  // happy = true;
}

/*
 * A parametrized constructor
 *
 * The this keyword is a pointer to a specific object
 * Good for use in constructors with parameters
*/
Cat::Cat(string name, int age) {
    this->name = name;
    this->age = age;
    cout << "Cat created with given name and age." << endl;
    happy = true;
}

// A destructor method
Cat::~Cat() {
  cout << "Cat destroyed" << endl;
}

void Cat::speak() {
    if (happy) {
        cout << "Meow!" << endl;
    } else {
        cout << "Sssss!" << endl;
    }
}

void Cat::setName(string name) {
    this->name = name;
} 

string Cat::getName() {
    return name;
}

int main() {
  // For the following, we could do this with int and other data types.

  // Allocating mem for single objects:
  Cat *cat = new Cat();
  delete cat;

  // Allocating mem for an array of objects (26, in this case):
  Cat *cats = new Cat[26];

  char c = 'a';
  string name(1, c); // Create a string containing one instance of the char variable c (name = "a")
  // c++; // variable c now is 'b'.

  // Try to assign names for each from a to z, and speak on each of them
  for (int i = 0; i < (sizeof(cats[0]) * 26)/sizeof(cats[0]); i++, c++) {
    string name(1,c);
    cats[i].setName(name);
    cout << "Cat " << cats[i].getName() << ":" << endl;
    cats[i].speak();
  }

  delete [] cats;

}