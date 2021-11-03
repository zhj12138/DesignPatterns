#ifndef LEARN_CREATIONALPATTERNS_SIMPLEFACTORY_SIMPLE_FACTORY_HPP_
#define LEARN_CREATIONALPATTERNS_SIMPLEFACTORY_SIMPLE_FACTORY_HPP_
#include <iostream>
#include <memory>

class Product {
 public:
  Product() = default;
  virtual ~Product() = default;
  virtual void use() = 0;
};
using ProductPtr = std::shared_ptr<Product>;

class ConcreteProductA : public Product {
 public:
  ConcreteProductA() = default;
  ~ConcreteProductA() override = default;
  void use() override {
    std::cout << "use ConcreteProductA" << std::endl;
  }
};

class ConcreteProductB : public Product {
 public:
  ConcreteProductB() = default;
  ~ConcreteProductB() override = default;
  void use() override {
    std::cout << "use ConcreteProductB" << std::endl;
  }
};

class Factory {
 public:
  static ProductPtr createProduct(std::string_view name) {
    if (name == "A") {
      return std::make_shared<ConcreteProductA>();
    } else {
      return std::make_shared<ConcreteProductB>();
    }
  }
};

#endif //LEARN_CREATIONALPATTERNS_SIMPLEFACTORY_SIMPLE_FACTORY_HPP_
