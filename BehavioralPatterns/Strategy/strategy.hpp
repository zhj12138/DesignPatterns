#ifndef LEARN_BEHAVIORALPATTERNS_STRATEGY_STRATEGY_HPP_
#define LEARN_BEHAVIORALPATTERNS_STRATEGY_STRATEGY_HPP_

#include <iostream>
#include <memory>

class Strategy {
 public:
  Strategy() = default;
  virtual ~Strategy() = default;
  virtual void algorithm() = 0;
};
using StrategyPtr = std::shared_ptr<Strategy>;

class ConcreteStrategyA : public Strategy {
 public:
  ConcreteStrategyA() = default;
  ~ConcreteStrategyA() override = default;
  void algorithm() override {
    std::cout << "algorithm A" << std::endl;
  }
};

class ConcreteStrategyB : public Strategy {
 public:
  ConcreteStrategyB() = default;
  ~ConcreteStrategyB() override = default;
  void algorithm() override {
    std::cout << "algorithm B" << std::endl;
  }
};

class Context {
 public:
  Context() = default;
  ~Context() = default;
  void setStrategy(StrategyPtr strategy) { strategy_ = std::move(strategy); }
  void algorithm() {
    strategy_->algorithm();
  }
 private:
  StrategyPtr strategy_;
};

#endif //LEARN_BEHAVIORALPATTERNS_STRATEGY_STRATEGY_HPP_
