#ifndef LEARN_STRUCTURALPATTERNS_BRIDGE_BRIDGE_HPP_
#define LEARN_STRUCTURALPATTERNS_BRIDGE_BRIDGE_HPP_

#include <iostream>
#include <memory>

/* Implementor */
class Skin {
 public:
  Skin() = default;
  virtual ~Skin() = default;
  virtual void show() = 0;
};
using SkinPtr = std::shared_ptr<Skin>;

/* ConcreteImplementor */
class CuteSkin : public Skin {
 public:
  CuteSkin() = default;
  ~CuteSkin() override = default;
  void show() override {
    std::cout << "skin: cute skin" << std::endl;
  }
};

/* ConcreteImplementor */
class CoolSkin : public Skin {
 public:
  CoolSkin() = default;
  ~CoolSkin() override = default;
  void show() override {
    std::cout << "skin: cool skin" << std::endl;
  }
};

/* Implementor */
class VideoFile {
 public:
  VideoFile() = default;
  virtual ~VideoFile() = default;
  virtual void decode() = 0;
};
using VideoFilePtr = std::shared_ptr<VideoFile>;

/* ConcreteImplementor */
class MPGFile : public VideoFile {
 public:
  MPGFile() = default;
  ~MPGFile() override = default;
  void decode() override {
    std::cout << "decode: MPG file" << std::endl;
  }
};

/* ConcreteImplementor */
class AVIFile : public VideoFile {
 public:
  AVIFile() = default;
  ~AVIFile() override = default;
  void decode() override {
    std::cout << "decode: AVI file" << std::endl;
  }
};

/* Abstraction */
class OperationSystemVersion {
 public:
  OperationSystemVersion() = default;
  virtual ~OperationSystemVersion() = default;
  void setSkin(SkinPtr skin) { skin_ = std::move(skin); }
  void setVideoFile(VideoFilePtr video_file) { video_file_ = std::move(video_file); }
  virtual void play() = 0;
 protected:
  SkinPtr skin_;
  VideoFilePtr video_file_;
};
using OperationSystemVersionPtr = std::shared_ptr<OperationSystemVersion>;

/* RefinedAbstraction */
class WindowsVersion : public OperationSystemVersion {
 public:
  WindowsVersion() = default;
  ~WindowsVersion() override = default;
  void play() override {
    video_file_->decode();
    skin_->show();
  }
};

/* RefinedAbstraction */
class LinuxVersion : public OperationSystemVersion {
 public:
  LinuxVersion() = default;
  ~LinuxVersion() override = default;
  void play() override {
    video_file_->decode();
    skin_->show();
  }
};

#endif //LEARN_STRUCTURALPATTERNS_BRIDGE_BRIDGE_HPP_
