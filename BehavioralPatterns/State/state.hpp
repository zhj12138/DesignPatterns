#ifndef LEARN_BEHAVIORALPATTERNS_STATE_STATE_HPP_
#define LEARN_BEHAVIORALPATTERNS_STATE_STATE_HPP_

#include <iostream>
#include <memory>

class State {
 public:
  State() = default;
  virtual ~State() = default;
  virtual void handle() = 0;
};
using StatePtr = std::shared_ptr<State>;

class ConcreteStateA : public State {
 public:
  ConcreteStateA() = default;
  ~ConcreteStateA() override = default;
  void handle() override {
    std::cout << "ConcreteStateA handled" << std::endl;
  }
};

class ConcreteStateB : public State {
 public:
  ConcreteStateB() = default;
  ~ConcreteStateB() override = default;
  void handle() override {
    std::cout << "ConcreteStateB handled" << std::endl;
  }
};

class Context {
 public:
  Context() = default;
  ~Context() = default;
  void setState(StatePtr state) { state_ = std::move(state); }
  void request() { state_->handle(); }
 private:
  StatePtr state_;
};

#endif //LEARN_BEHAVIORALPATTERNS_STATE_STATE_HPP_
