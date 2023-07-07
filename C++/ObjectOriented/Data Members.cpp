#include <iostream>
using namespace std;

class Cat {
public:
    void speak();
    void makeHappy();
    void makeAngry();
private:
    bool happy;
};

void Cat::speak() {
    if (happy) {
        cout << "Meow!" << endl;
    } else {
        cout << "Sssss!" << endl;
    }
}

void Cat::makeHappy() {
    happy = true;
}

void Cat::makeAngry() {
    happy = false;
}

int main() {
    Cat jim;
    jim.makeHappy();

    Cat bob;
    bob.makeAngry();

    jim.speak();
    bob.speak();
}