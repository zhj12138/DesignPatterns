#include "decorator.hpp"

int main() {
  ComponentPtr component = std::make_shared<ConcreteComponent>();
  DecoratorPtr decorator_a = std::make_shared<ConcreteDecoratorA>(component);
  DecoratorPtr decorator_b = std::make_shared<ConcreteDecoratorB>(component);
  decorator_a->operation(); // ConcreteComponent operation\nDecoratorA add behavior
  decorator_b->operation(); // ConcreteComponent operation\nDecoratorB add behavior
  return 0;
}