#include "state.hpp"

int main() {
  Context context;
  StatePtr state_a = std::make_shared<ConcreteStateA>();
  StatePtr state_b = std::make_shared<ConcreteStateB>();
  context.setState(state_a);
  context.request();
  context.setState(state_b);
  context.request();
  return 0;
}