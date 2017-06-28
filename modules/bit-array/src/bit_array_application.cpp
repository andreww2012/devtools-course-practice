// Copyright 2017 Kazakov Andrew

#include "include/bit_array_application.h"

#include <string>

BitArrayApp::BitArrayApp() : message_("") {}

void BitArrayApp::Help(const char* appname, const char* message) {
  message_ = std::string(message) +
    "This is a bit array application.\n\n" +
    "In fact, this app doesn't make any sense. The only purpose " +
    "of this application is to show you how a bit array works."
    "Please provide arguments in the following format:\n\n"+

    "  $ " + appname + " <bit-array1> <bit-array2> <command>\n\n" +

    "where <bit-array> is a binary string.\n\n" +
    "The list of the possible commands with its arguments:\n" +
    "  getsize\t\t returns size of the first bit array\n" +
    "  set <bit-number>\t\t sets bit in the first bit array\n" +
    "  clear <bit-number>\t\t clears bit in the first bit array\n" +
    "  invert\t\t inverts the first bit array\n" +
    "  union\t\t the \"union\" operation on the bit arrays\n " +
    "  intersection\t\t the \"intersection\" operation on the bit arrays\n " +
    "  xor\t\t the \"xor\" operation on the bit arrays.";
}

void BitArrayApp::ParseBitArray(const std::string& bit_array) {
  const int bit_array_size = bit_array.size();

  BitArray ba(bit_array_size);

  for (int i = 0; i < bit_array_size; i++) {
    if (bit_array[i] == 1) {
      ba.SetBit(i);
    } else if (bit_array[i] != 0) {
      throw 1;
    }
  }

  bit_array1_ = ba;
}

std::string BitArrayApp::operator()(int argc, const char** argv) {
  if (argc == 1) {
    Help(argv[0]);
    return message_;
  } else if (argc < 4) {
    Help(argv[0], "Error: should be 3 or 4 arguments.\n\n");
    return message_;
  }

  std::string bit_array_str1 = argv[1];
  std::string bit_array_str2 = argv[2];
  std::string command = argv[3];
  int command_argument = -1;

  if (argc == 5) {
    command_argument = std::stoi(std::string(argv[4]));
  }

  try {
    ParseBitArray(bit_array_str1);
    ParseBitArray(bit_array_str2);
  } catch (int e) {
    Help(argv[0], "Error: there is an incorrect bit array.\n\n");
    return message_;
  }

  BitArray ba;

  if (command == "getsize") {
    message_ = bit_array1_.GetSize();
  } else if (command == "set") {
    try {
      bit_array1_.SetBit(command_argument);
    }
    catch (std::string& e) {
      Help(argv[0], "Error: incorrect index.\n\n");
    }
  } else if (command == "clear") {
    try {
      bit_array1_.ClearBit(command_argument);
    }
    catch (std::string& e) {
      Help(argv[0], "Error: incorrect index.\n\n");
    }
  } else if (command == "invert") {
    ba = ~bit_array1_;
    message_ = ba.ToString();
  } else if (command == "union") {
    ba = bit_array1_ | bit_array2_;
    message_ = ba.ToString();
  } else if (command == "intersection") {
    ba = bit_array1_ & bit_array2_;
    message_ = ba.ToString();
  } else if (command == "xor") {
    ba = bit_array1_ ^ bit_array2_;
    message_ = ba.ToString();
  } else {
    Help(argv[0], "Error: command is not specified.");
  }

  return message_;
}
