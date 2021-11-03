#include "factory_method.hpp"

int main() {
  LogFactoryPtr file_log_factory = std::make_shared<FileLogFactory>();
  LogFactoryPtr database_log_factory = std::make_shared<DatabaseLogFactory>();
  LogPtr file_log = file_log_factory->createLog();
  LogPtr database_log = database_log_factory->createLog();
  file_log->writeLog();     // write file log
  database_log->writeLog(); // write database log
  return 0;
}