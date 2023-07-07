#include <iostream>
using namespace std;

class Cat {
public:
    Cat(); // Constructor
    ~Cat(); // Destructor
    void speak();
private:
    bool happy;
};

Cat::Cat() {
  cout << "Cat created" << endl;
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