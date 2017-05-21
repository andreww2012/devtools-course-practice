// Copyright 2017 Kazakov Andrew

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_
#define MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_

#include <string>

class Application {
 public:
  Application();
  std::string operator()(int argc, const char** argv);

 private:
  void Help(const char* appname, const char* message = "");
  bool ValidateNumberOfArguments(int argc, const char** argv);

  std::string message_;
  typedef struct {

  } Arguments;
};

#endif // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_
