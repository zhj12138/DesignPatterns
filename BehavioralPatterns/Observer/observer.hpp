#ifndef LEARN_BEHAVIORALPATTERNS_OBSERVER_OBSERVER_HPP_
#define LEARN_BEHAVIORALPATTERNS_OBSERVER_OBSERVER_HPP_

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Subject;
using SubjectPtr = std::shared_ptr<Subject>;

class Observer {
 public:
  Observer() = default;
  virtual ~Observer() = default;
  virtual void update(Subject *subject) = 0;
};
using ObserverPtr = std::shared_ptr<Observer>;

class ConcreteObserver : public Observer {
 public:
  explicit ConcreteObserver(int state) : state_(state) {}
  ~ConcreteObserver() override = default;
  void update(Subject *subject) override {
    std::cout << "ConcreteObserver updated" << std::endl;
  }
 private:
  int state_;
};

class Subject {
 public:
  Subject() = default;
  virtual ~Subject() = default;
  void attach(const ObserverPtr &observer) {
    observers_.push_back(observer);
  }
  void detach(const ObserverPtr &observer) {
    observers_.erase(std::find(observers_.begin(), observers_.end(), observer));
  }
  void notify() {
    std::for_each(observers_.begin(), observers_.end(), [this](const ObserverPtr &observer) {
      observer->update(this);
    });
  }
  virtual int getState() = 0;
  virtual void setState(int state) = 0;
 private:
  std::vector<ObserverPtr> observers_;
};

class ConcreteSubject : public Subject {
 public:
  explicit ConcreteSubject(int state) : state_(state) {}
  ~ConcreteSubject() override = default;
  int getState() override { return state_; }
  void setState(int state) override { state_ = state; }
 private:
  int state_;
};

#endif //LEARN_BEHAVIORALPATTERNS_OBSERVER_OBSERVER_HPP_
