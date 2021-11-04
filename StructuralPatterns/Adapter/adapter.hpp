#ifndef LEARN_STRUCTURALPATTERNS_ADAPTER_ADAPTER_HPP_
#define LEARN_STRUCTURALPATTERNS_ADAPTER_ADAPTER_HPP_

#include <iostream>
#include <memory>

class Target {
 public:
  Target() = default;
  virtual ~Target() = default;
  virtual void request() = 0;
};

class Adaptee {
 public:
  Adaptee() = default;
  ~Adaptee() = default;
  void specific_request() {
    std::cout << "specific request" << std::endl;
  }
};
using AdapteePtr = std::shared_ptr<Adaptee>;

class ObjectAdapter : public Target {
 public:
  explicit ObjectAdapter(AdapteePtr adaptee) : adaptee_(std::move(adaptee)) {}
  ~ObjectAdapter() override = default;
  void request() override {
    adaptee_->specific_request();
  }
 private:
  AdapteePtr adaptee_;
};

class ClassAdapter : public Target, private Adaptee {
 public:
  ClassAdapter() = default;
  ~ClassAdapter() override = default;
  void request() override {
    specific_request();
  }
};

#endif //LEARN_STRUCTURALPATTERNS_ADAPTER_ADAPTER_HPP_
