#include "simple_factory.hpp"

int main() {
  ProductPtr a = Factory::createProduct("A");
  ProductPtr b = Factory::createProduct("B");
  a->use(); // use ConcreteProductA
  b->use(); // use ConcreteProductB
  return 0;
}