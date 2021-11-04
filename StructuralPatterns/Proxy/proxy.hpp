#ifndef LEARN_STRUCTURALPATTERNS_PROXY_PROXY_HPP_
#define LEARN_STRUCTURALPATTERNS_PROXY_PROXY_HPP_

#include <iostream>
#include <memory>

class Subject {
 public:
  Subject() = default;
  virtual ~Subject() = default;
  virtual void request() = 0;
};
using SubjectPtr = std::shared_ptr<Subject>;

class RealSubject : public Subject {
 public:
  RealSubject() = default;
  ~RealSubject() override = default;
  void request() override {
    std::cout << "RealSubject request" << std::endl;
  }
};

class Proxy {
 public:
  Proxy() : subject_(std::make_shared<RealSubject>()) {}
  ~Proxy() = default;
  void request() {
    preRequest();
    subject_->request();
    afterRequest();
  }
 private:
  void preRequest() {
    std::cout << "Proxy preRequest" << std::endl;
  }
  void afterRequest() {
    std::cout << "Proxy afterRequest" << std::endl;
  }
  SubjectPtr subject_;
};

#endif //LEARN_STRUCTURALPATTERNS_PROXY_PROXY_HPP_
