#include "mediator.hpp"

int main() {
  ColleaguePtr colleague_a = std::make_shared<ConcreteColleagueA>();
  ColleaguePtr colleague_b = std::make_shared<ConcreteColleagueB>();
  MediatorPtr mediator = std::make_shared<ConcreteMediator>();
  mediator->register1(1, colleague_a);
  mediator->register1(2, colleague_b);
  colleague_a->sendMsg(2, "Hello, B!");
  colleague_b->sendMsg(1, "Hello, A!");
  return 0;
}
