#include "flyweight.hpp"

int main() {
  FlyweightFactory factory;
  factory.getFlyweight(1)->operation();
  factory.getFlyweight(2)->operation();
  factory.getFlyweight(1)->operation();
  return 0;
}