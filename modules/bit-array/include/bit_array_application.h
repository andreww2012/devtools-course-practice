// Copyright 2017 Kazakov Andrew

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_
#define MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_

#include "include/bit_array.h"

#include <string>

class BitArrayApp {
 public:
  BitArrayApp(void);
  std::string operator()(int argc, const char** argv);

 private:
  std::string message_;
  BitArray bit_array1_, bit_array2_;

  void Help(const char* appname, const char* message = "");
  static void ParseBitArray(const std::string& bit_array_str, BitArray*);
};

#endif  // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_
