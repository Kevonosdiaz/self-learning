#include <iostream>
#include "Cat.h"
#include "Animals.h"
using namespace std;
using namespace kt; // We can select a namespace

/**
 * As a side note, we can use:
 * g++ Namespaces.cpp Animals.h Animals.cpp Cat.cpp Cat.h
 * ./a.out
 * To compile this (or add -o name)

*/
int main() {
  Cat cat;
  cat.speak();

  cats::Cat cat2;
  cat2.speak();
  return 0;
}