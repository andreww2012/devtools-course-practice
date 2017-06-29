// Copyright 2017 Kazakov Andrew

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/bit_array_application.h"

int main(int argc, const char** argv) {
  BitArrayApp app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());

  return 0;
}
