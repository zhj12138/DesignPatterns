#include "bridge.hpp"

int main() {
  OperationSystemVersionPtr player = std::make_shared<WindowsVersion>();
  player->setSkin(std::make_shared<CuteSkin>());
  player->setVideoFile(std::make_shared<MPGFile>());
  player->play();
  return 0;
}