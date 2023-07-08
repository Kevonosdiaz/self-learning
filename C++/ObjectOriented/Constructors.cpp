#include <iostream>
using namespace std;

class Cat {
public:
    Cat(); // Constructor
    Cat(string name, int age); // Overloading constructor to allow for including name and age;
    ~Cat(); // Destructor
    void speak();
private:
    bool happy;
    string name;
    int age;
};

Cat::Cat() {
  cout << "Cat created" << endl;
  happy = true;
}

Cat::Cat(string catName, int catAge) {
    name = catName;
    age = catAge;
    cout << "Cat created with name and age" << endl;
    happy = true;
}

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

int main() {
    Cat jim;
    Cat bob;

    jim.speak();
    bob.speak();
}