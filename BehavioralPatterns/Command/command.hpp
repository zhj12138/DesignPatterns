#ifndef LEARN_BEHAVIORALPATTERNS_COMMAND_COMMAND_HPP_
#define LEARN_BEHAVIORALPATTERNS_COMMAND_COMMAND_HPP_

#include <iostream>
#include <memory>

class Television {
 public:
  Television() = default;
  ~Television() = default;
  void open() {
    std::cout << "Television is open" << std::endl;
  }
  void off() {
    std::cout << "Television is off" << std::endl;
  }
};
using TelevisionPtr = std::shared_ptr<Television>;

class Command {
 public:
  Command() = default;
  virtual ~Command() = default;
  virtual void execute() = 0;
};
using CommandPtr = std::shared_ptr<Command>;

class TVOpenCommand : public Command {
 public:
  explicit TVOpenCommand(TelevisionPtr television) : television_(std::move(television)) {}
  ~TVOpenCommand() override = default;
  void execute() override {
    television_->open();
  }
 private:
  TelevisionPtr television_;
};

class TVCloseCommand : public Command {
 public:
  explicit TVCloseCommand(TelevisionPtr television) : television_(std::move(television)) {}
  ~TVCloseCommand() override = default;
  void execute() override {
    television_->off();
  }
 private:
  TelevisionPtr television_;
};

class Controller {
 public:
  explicit Controller(const TelevisionPtr &television)
      : open_command(std::make_shared<TVOpenCommand>(television)),
        off_command(std::make_shared<TVCloseCommand>(television)) {
  }
  ~Controller() = default;
  void open() {
    open_command->execute();
  }
  void off() {
    off_command->execute();
  }
 private:
  CommandPtr open_command;
  CommandPtr off_command;
};

#endif //LEARN_BEHAVIORALPATTERNS_COMMAND_COMMAND_HPP_
