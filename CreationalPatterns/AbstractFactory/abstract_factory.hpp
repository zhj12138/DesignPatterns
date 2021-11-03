#ifndef LEARN_CREATIONALPATTERNS_ABSTRACTFACTORY_ABSTRACT_FACTORY_HPP_
#define LEARN_CREATIONALPATTERNS_ABSTRACTFACTORY_ABSTRACT_FACTORY_HPP_

#include <iostream>
#include <memory>

class AbstractProductA {
 public:
  AbstractProductA() = default;
  virtual ~AbstractProductA() = default;
  virtual void use() = 0;
};
using AbstractProductAPtr = std::shared_ptr<AbstractProductA>;

class ProductA1 : public AbstractProductA {
 public:
  ProductA1() = default;
  ~ProductA1() override = default;
  void use() override {
    std::cout << "use ProductA1" << std::endl;
  }
};

class ProductA2 : public AbstractProductA {
 public:
  ProductA2() = default;
  ~ProductA2() override = default;
  void use() override {
    std::cout << "use ProductA2" << std::endl;
  }
};

class AbstractProductB {
 public:
  AbstractProductB() = default;
  virtual ~AbstractProductB() = default;
  virtual void eat() = 0;
};
using AbstractProductBPtr = std::shared_ptr<AbstractProductB>;

class ProductB1 : public AbstractProductB {
 public:
  ProductB1() = default;
  ~ProductB1() override = default;
  void eat() override {
    std::cout << "eat ProductB1" << std::endl;
  }
};

class ProductB2 : public AbstractProductB {
 public:
  ProductB2() = default;
  ~ProductB2() override = default;
  void eat() override {
    std::cout << "eat ProductB2" << std::endl;
  }
};

class AbstractFactory {
 public:
  AbstractFactory() = default;
  virtual ~AbstractFactory() = default;
  virtual AbstractProductAPtr createProductA() = 0;
  virtual AbstractProductBPtr createProductB() = 0;
};
using AbstractFactoryPtr = std::shared_ptr<AbstractFactory>;

class ConcreteFactory1 : public AbstractFactory {
 public:
  ConcreteFactory1() = default;
  ~ConcreteFactory1() override = default;
  AbstractProductAPtr createProductA() override {
    return std::make_shared<ProductA1>();
  }
  AbstractProductBPtr createProductB() override {
    return std::make_shared<ProductB1>();
  }
};

class ConcreteFactory2 : public AbstractFactory {
 public:
  ConcreteFactory2() = default;
  ~ConcreteFactory2() override = default;
  AbstractProductAPtr createProductA() override {
    return std::make_shared<ProductA2>();
  }
  AbstractProductBPtr createProductB() override {
    return std::make_shared<ProductB2>();
  }
};

#endif //LEARN_CREATIONALPATTERNS_ABSTRACTFACTORY_ABSTRACT_FACTORY_HPP_
