#ifndef LEARN_BEHAVIORALPATTERNS_MEDIATOR_MEDIATOR_HPP_
#define LEARN_BEHAVIORALPATTERNS_MEDIATOR_MEDIATOR_HPP_

#include <iostream>
#include <memory>
#include <unordered_map>

class Colleague;
using ColleaguePtr = std::shared_ptr<Colleague>;

class Mediator {
 public:
  Mediator() = default;
  virtual ~Mediator() = default;
  virtual void operation(int id, const std::string &msg) = 0;
  virtual void register1(int id, ColleaguePtr colleague) = 0;
};
using MediatorPtr = std::shared_ptr<Mediator>;

class Colleague {
 public:
  Colleague() = default;
  virtual ~Colleague() = default;
  void setMediator(Mediator *mediator) {
    mediator_ = mediator;
  }
  virtual void sendMsg(int id, const std::string &msg) {
    mediator_->operation(id, msg);
  }
  virtual void receiveMsg(const std::string &msg) {
    std::cout << "Collegue receive msg: " << msg << std::endl;
  }
 protected:
  Mediator *mediator_{nullptr};
};

class ConcreteColleagueA : public Colleague {
 public:
  ConcreteColleagueA() = default;
  ~ConcreteColleagueA() override = default;
  void receiveMsg(const std::string &msg) override {
    std::cout << "ConcreteCollegueA receive msg: " << msg << std::endl;
  }
};

class ConcreteColleagueB : public Colleague {
 public:
  ConcreteColleagueB() = default;
  ~ConcreteColleagueB() override = default;
  void receiveMsg(const std::string &msg) override {
    std::cout << "ConcreteCollegueB receive msg: " << msg << std::endl;
  }
};

class ConcreteMediator : public Mediator {
 public:
  ConcreteMediator() = default;
  ~ConcreteMediator() override = default;
  void operation(int id, const std::string &msg) override {
    colleagues_[id]->receiveMsg(msg);
  }
  void register1(int id, ColleaguePtr colleague) override {
    colleagues_.emplace(id, colleague);
    colleague->setMediator(this);
  }
 private:
  std::unordered_map<int, ColleaguePtr> colleagues_;
};

#endif //LEARN_BEHAVIORALPATTERNS_MEDIATOR_MEDIATOR_HPP_
