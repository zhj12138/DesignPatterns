#ifndef LEARN_STRUCTURALPATTERNS_FACADE_FACADE_HPP_
#define LEARN_STRUCTURALPATTERNS_FACADE_FACADE_HPP_

#include <iostream>
#include <memory>

class SystemA {
 public:
  SystemA() = default;
  ~SystemA() = default;
  void operationA() {
    std::cout << "operationA" << std::endl;
  }
};
using SystemAPtr = std::shared_ptr<SystemA>;

class SystemB {
 public:
  SystemB() = default;
  ~SystemB() = default;
  void operationB() {
    std::cout << "operationB" << std::endl;
  }
};
using SystemBPtr = std::shared_ptr<SystemB>;

class SystemC {
 public:
  SystemC() = default;
  ~SystemC() = default;
  void operationC() {
    std::cout << "operationC" << std::endl;
  }
};
using SystemCPtr = std::shared_ptr<SystemC>;

class Facade {
 public:
  Facade()
      : system_a_(std::make_shared<SystemA>()),
        system_b_(std::make_shared<SystemB>()),
        system_c_(std::make_shared<SystemC>()) {
  }
  ~Facade() = default;
  void wrapOperation() {
    system_a_->operationA();
    system_b_->operationB();
    system_c_->operationC();
  }
 private:
  SystemAPtr system_a_;
  SystemBPtr system_b_;
  SystemCPtr system_c_;
};

#endif //LEARN_STRUCTURALPATTERNS_FACADE_FACADE_HPP_
