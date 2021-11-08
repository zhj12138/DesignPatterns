#include "command.hpp"

int main() {
  TelevisionPtr television = std::make_shared<Television>();
  Controller controller(television);
  controller.open();
  controller.off();
  return 0;
}