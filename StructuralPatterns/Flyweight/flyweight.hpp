#ifndef LEARN_STRUCTURALPATTERNS_FLYWEIGHT_FLYWEIGHT_HPP_
#define LEARN_STRUCTURALPATTERNS_FLYWEIGHT_FLYWEIGHT_HPP_

#include <iostream>
#include <memory>
#include <unordered_map>

class Flyweight {
 public:
  Flyweight() = default;
  virtual ~Flyweight() = default;
  virtual void operation() = 0;
};
using FlyweightPtr = std::shared_ptr<Flyweight>;

class ConcreteFlyweight : public Flyweight {
 public:
  explicit ConcreteFlyweight(int intrinsic_state) : intrinsic_state_(intrinsic_state) {}
  ~ConcreteFlyweight() override = default;
  void operation() {
    std::cout << "intrinsic_state: " << intrinsic_state_ << std::endl;
  }
 private:
  int intrinsic_state_;
};

class UnsharedConcreteFlyweight : public Flyweight {
 public:
  explicit UnsharedConcreteFlyweight(int all_state) : all_state_(all_state) {}
  ~UnsharedConcreteFlyweight() override = default;
  void operation() {
    std::cout << "all_state: " << all_state_ << std::endl;
  }
 private:
  int all_state_;
};

class FlyweightFactory {
 public:
  FlyweightFactory() = default;
  ~FlyweightFactory() = default;
  FlyweightPtr getFlyweight(int key) {
    if (map_.find(key) != map_.end()) {
      return map_[key];
    }
    auto new_flyweight = std::make_shared<ConcreteFlyweight>(key);
    map_.emplace(key, new_flyweight);
    return new_flyweight;
  }
 private:
  std::unordered_map<int, FlyweightPtr> map_;
};

#endif //LEARN_STRUCTURALPATTERNS_FLYWEIGHT_FLYWEIGHT_HPP_
