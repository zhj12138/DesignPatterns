#include "observer.hpp"

int main() {
  SubjectPtr subject = std::make_shared<ConcreteSubject>(1);
  ObserverPtr observer_a = std::make_shared<ConcreteObserver>(1);
  ObserverPtr observer_b = std::make_shared<ConcreteObserver>(2);
  subject->attach(observer_a);
  subject->setState(2);
  subject->notify();
  subject->detach(observer_a);
  subject->attach(observer_b);
  subject->setState(1);
  subject->notify();
  return 0;
}