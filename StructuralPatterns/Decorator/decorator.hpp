#ifndef LEARN_STRUCTURALPATTERNS_DECORATOR_DECORATOR_HPP_
#define LEARN_STRUCTURALPATTERNS_DECORATOR_DECORATOR_HPP_

#include <iostream>
#include <memory>

class Component {
 public:
  Component() = default;
  virtual ~Component() = default;
  virtual void operation() = 0;
};
using ComponentPtr = std::shared_ptr<Component>;

class ConcreteComponent : public Component {
 public:
  ConcreteComponent() = default;
  ~ConcreteComponent() override = default;
  void operation() override {
    std::cout << "ConcreteComponent operation" << std::endl;
  }
};

class Decorator {
 public:
  explicit Decorator(ComponentPtr component) : component_(std::move(component)) {}
  virtual ~Decorator() = default;
  virtual void operation() {
    component_->operation();
  }
 private:
  ComponentPtr component_;
};
using DecoratorPtr = std::shared_ptr<Decorator>;

class ConcreteDecoratorA : public Decorator {
 public:
  explicit ConcreteDecoratorA(ComponentPtr component) : Decorator(std::move(component)) {}
  ~ConcreteDecoratorA() override = default;
  void operation() override {
    Decorator::operation();
    addBehavior();
  }
 private:
  void addBehavior() {
    std::cout << "DecoratorA add behavior" << std::endl;
  }
};

class ConcreteDecoratorB : public Decorator {
 public:
  explicit ConcreteDecoratorB(ComponentPtr component) : Decorator(std::move(component)) {}
  ~ConcreteDecoratorB() override = default;
  void operation() override {
    Decorator::operation();
    addBehavior();
  }
 private:
  void addBehavior() {
    std::cout << "DecoratorB add behavior" << std::endl;
  }
};

#endif //LEARN_STRUCTURALPATTERNS_DECORATOR_DECORATOR_HPP_
