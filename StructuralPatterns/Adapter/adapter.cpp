#include "adapter.hpp"

int main() {
  ClassAdapter class_adapter;
  class_adapter.request();
  ObjectAdapter object_adapter(std::make_shared<Adaptee>());
  object_adapter.request();
}