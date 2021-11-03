#include "singleton.hpp"

int main() {
  SingletonPtr instance = Singleton::getInstance();
  instance->singletonOperation();
  MeyerThreadsafeSingleton::getInstance().singletonOperation();
  return 0;
}