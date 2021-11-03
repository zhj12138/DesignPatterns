#include "abstract_factory.hpp"

int main() {
  AbstractFactoryPtr factory1 = std::make_shared<ConcreteFactory1>();
  AbstractFactoryPtr factory2 = std::make_shared<ConcreteFactory2>();
  AbstractProductAPtr product_a1 = factory1->createProductA();
  AbstractProductBPtr product_b1 = factory1->createProductB();
  AbstractProductAPtr product_a2 = factory2->createProductA();
  AbstractProductBPtr product_b2 = factory2->createProductB();
  product_a1->use();  // use ProductA1
  product_b1->eat();  // eat ProductB1
  product_a2->use();  // use ProductA2
  product_b2->eat();  // eat ProductB2
  return 0;
}