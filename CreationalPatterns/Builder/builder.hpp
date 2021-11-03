#ifndef LEARN_CREATIONALPATTERNS_BUILDER_BUILDER_HPP_
#define LEARN_CREATIONALPATTERNS_BUILDER_BUILDER_HPP_

#include <iostream>
#include <memory>

/* Product */
class Meal {
 public:
  Meal() = default;
  ~Meal() = default;
  // 注：以下两个函数最好添加[[nodiscard]]属性(C++17语法)，但为了让代码更简洁，我将其略去，之后的代码会做同样的处理
  const std::string &getFood() const { return food_; }
  const std::string &getDrink() const { return drink_; }
  void setFood(const std::string &food) { food_ = food; }
  void setDrink(const std::string &drink) { drink_ = drink; }
 private:
  std::string food_;
  std::string drink_;
};

std::ostream &operator<<(std::ostream &os, const Meal &meal) {
  os << "Meal(food: " << meal.getFood() << ", drink: " << meal.getDrink() << ")";
  return os;
}

/* Builder */
class MealBuilder {
 public:
  MealBuilder() = default;
  virtual ~MealBuilder() = default;
  virtual void buildFood() = 0;
  virtual void buildDrink() = 0;
  Meal getMeal() const { return meal_; }
 protected:
  Meal meal_;
};
using MealBuilderPtr = std::shared_ptr<MealBuilder>;

/* ConcreteBuilder */
class SubMealBuilderA : public MealBuilder {
 public:
  SubMealBuilderA() = default;
  ~SubMealBuilderA() override = default;
  void buildFood() override {
    meal_.setFood("FoodA");
  }
  void buildDrink() override {
    meal_.setDrink("DrinkA");
  }
};

/* ConcreteBuilder */
class SubMealBuilderB : public MealBuilder {
 public:
  SubMealBuilderB() = default;
  ~SubMealBuilderB() override = default;
  void buildFood() override {
    meal_.setFood("FoodB");
  }
  void buildDrink() override {
    meal_.setDrink("DrinkB");
  }
};

/* Director */
class KFCWaiter {
 public:
  KFCWaiter() = default;
  ~KFCWaiter() = default;
  void setMealBuilder(const MealBuilderPtr &builder) { builder_ = builder; }
  void construct() {
    builder_->buildFood();
    builder_->buildDrink();
  }
  Meal getMeal() {
    return builder_->getMeal();
  }
 private:
  MealBuilderPtr builder_;
};

#endif //LEARN_CREATIONALPATTERNS_BUILDER_BUILDER_HPP_
