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

// A copy constructor that copies all fields of another pre-existing Cat (note how we can refer to other.__ both inside and outside the {})
// This can be used via the "=" (newcat = oldcat) operator or Cat cat3(cat1), where cat3 is a copy of cat1.
Cat::Cat(const Cat& other): name(other.name), age(other.age) {happy = other.happy; cout << "Copied a cat." << endl;}

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

// This method is designed to demonstrate how to return an object via pointer in a function (note that it still needs to be deallocated outside of function scope)
Cat *createCat() {
    Cat *pCat = new Cat();
    pCat -> setName("Tyson");
    return pCat;
}

int main() {
    Cat jim;
    Cat bob;

    jim.speak();
    bob.speak();

    // When using the "new" keyword, we need to call delete to deallocate the memory!
    Cat *pCat = new Cat();
    pCat -> setName("Charles");
    pCat -> getName();

    delete pCat; // For every usage of "new", call "delete" eventually (to avoid memory leaks)

    // Usage of a function returning a Cat pointer
    Cat *pCat2 = createCat();
    pCat2 -> speak();
    delete pCat2;


    // Reminder that the length of a pointer is the length of a "long" (64-bit)
    cout << sizeof(pCat);

    return 0;
}