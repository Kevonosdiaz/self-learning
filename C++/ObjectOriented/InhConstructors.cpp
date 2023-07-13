#include <iostream>
using namespace std;

/**
 * We can let this superclass initialize private data that is stored by Vehicle
*/
class Machine {
  int id; // automatically private since not in public section
  public:
    Machine(): id(0) {cout << "Machine no-arg constructor called." << endl;}
    Machine(int id): id(id) {cout << "Machine parametrized constructor called." << endl;}
};

class Vehicle: public Machine {
  public:
    Vehicle() {cout << "Vehicle no-arg constructor called." << endl;}
    Vehicle(int id): Machine(id) {cout << "Vehicle parametrized constructor called." << endl;}
};

int main() {
  Vehicle vehicle; // This will call both the Machine and Vehicle no-arg constructors
  cout << "Some filler..." << endl;
  Vehicle vehicle(123); // This will call both of the Machine/Vehicle parametrized constructors, passing the id to the Machine constructor.
  
  return 0;
}