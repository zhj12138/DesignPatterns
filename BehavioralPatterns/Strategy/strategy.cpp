#include "strategy.hpp"

int main() {
  Context context;
  StrategyPtr strategy_a = std::make_shared<ConcreteStrategyA>();
  StrategyPtr strategy_b = std::make_shared<ConcreteStrategyB>();
  context.setStrategy(strategy_a);
  context.algorithm();
  context.setStrategy(strategy_b);
  context.algorithm();
  return 0;
}
