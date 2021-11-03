#include "builder.hpp"

int main() {
  MealBuilderPtr builder_a = std::make_shared<SubMealBuilderA>();
  MealBuilderPtr builder_b = std::make_shared<SubMealBuilderB>();
  KFCWaiter waiter;
  waiter.setMealBuilder(builder_a);
  waiter.construct();
  std::cout << waiter.getMeal() << std::endl; // Meal(food: FoodA, drink: DrinkA)
  waiter.setMealBuilder(builder_b);
  waiter.construct();
  std::cout << waiter.getMeal() << std::endl; // Meal(food: FoodB, drink: DrinkB)
  return 0;
}