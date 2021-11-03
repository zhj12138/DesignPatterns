#ifndef LEARN_CREATIONALPATTERNS_SINGLETON_SINGLETON_HPP_
#define LEARN_CREATIONALPATTERNS_SINGLETON_SINGLETON_HPP_

#include <iostream>
#include <memory>

class noncopyable {
 public:
  noncopyable(const noncopyable &) = delete;
  noncopyable &operator=(const noncopyable &) = delete;
 protected:
  noncopyable() = default;
  ~noncopyable() = default;
};

class Singleton : public noncopyable {
 public:
  ~Singleton() = default;
  static std::shared_ptr<Singleton> getInstance() {
    if (!instance_) {
      instance_.reset(new Singleton);
    }
    return instance_;
  }
  void singletonOperation() {
    std::cout << "singleton operation" << std::endl;
  }
 private:
  Singleton() = default;
  static std::shared_ptr<Singleton> instance_;
};
using SingletonPtr = std::shared_ptr<Singleton>;
SingletonPtr Singleton::instance_ = nullptr;

class MeyerThreadsafeSingleton : public noncopyable {
 public:
  static MeyerThreadsafeSingleton& getInstance() {
    static MeyerThreadsafeSingleton instance;
    return instance;
  }
  void singletonOperation() {
    std::cout << "singleton operation" << std::endl;
  }
 private:
  MeyerThreadsafeSingleton() = default;
  ~MeyerThreadsafeSingleton() = default;
};

#endif //LEARN_CREATIONALPATTERNS_SINGLETON_SINGLETON_HPP_
