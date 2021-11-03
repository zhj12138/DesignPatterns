#ifndef LEARN_CREATIONALPATTERNS_FACTORYMETHOD_FACTORY_METHOD_HPP_
#define LEARN_CREATIONALPATTERNS_FACTORYMETHOD_FACTORY_METHOD_HPP_

#include <iostream>
#include <memory>

/* Product */
class Log {
 public:
  Log() = default;
  virtual ~Log() = default;
  virtual void writeLog() = 0;
};
using LogPtr = std::shared_ptr<Log>;

/* ConcreteProduct */
class FileLog : public Log {
 public:
  FileLog() = default;
  ~FileLog() override = default;
  void writeLog() override {
    std::cout << "write file log" << std::endl;
  }
};

/* ConcreteProduct */
class DatabaseLog : public Log {
 public:
  DatabaseLog() = default;
  ~DatabaseLog() override = default;
  void writeLog() override {
    std::cout << "write database log" << std::endl;
  }
};

/* Factory */
class LogFactory {
 public:
  LogFactory() = default;
  virtual ~LogFactory() = default;
  virtual LogPtr createLog() = 0;
};
using LogFactoryPtr = std::shared_ptr<LogFactory>;

/* ConcreteFactory */
class FileLogFactory : public LogFactory {
 public:
  FileLogFactory() = default;
  ~FileLogFactory() override = default;
  LogPtr createLog() override {
    return std::make_shared<FileLog>();
  }
};

/* ConcreteFactory */
class DatabaseLogFactory : public LogFactory {
 public:
  DatabaseLogFactory() = default;
  ~DatabaseLogFactory() override = default;
  LogPtr createLog() override {
    return std::make_shared<DatabaseLog>();
  }
};

#endif //LEARN_CREATIONALPATTERNS_FACTORYMETHOD_FACTORY_METHOD_HPP_
