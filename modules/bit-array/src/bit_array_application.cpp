// Copyright 2017 Kazakov Andrew

#include "include/bit_array_application.h"

#include <string>
#include <sstream>

BitArrayApp::BitArrayApp() : message_("") {}

void BitArrayApp::Help(const char* appname, const char* message) {
  message_ = std::string(message) +
    "This is a bit array application.\n" +
    "In fact, this app doesn't make any sense. The only purpose " +
    "of this application is to show you how a bit array works.\n"
    "Please provide arguments in the following format:\n\n"+

    "  $ " + appname + " <bit-array1> <bit-array2> <command>\n\n" +

    "where <bit-array> is a binary string.\n" +
    "The list of the possible commands with its arguments:\n" +
    " getsize\t\t returns size of the first bit array\n" +
    " set <bit num>\t\t sets bit in the first bit array\n" +
    " clear <bit num>\t\t clears bit in the first bit array\n" +
    " invert\t\t inverts the first bit array\n" +
    " union\t\t the \"union\" operation on the bit arrays\n" +
    " inter\t\t the \"intersection\" operation on the bit arrays\n" +
    " xor\t\t the \"xor\" operation on the bit arrays.";
}

void BitArrayApp::ParseBitArray(const std::string& bit_array_str,
BitArray* bit_array) {
  const int bit_array_size = bit_array_str.size();

  BitArray ba(bit_array_size);

  for (int i = 0; i < bit_array_size; i++) {
    if (bit_array_str[i] == '1') {
      ba.SetBit(i);
    } else if (bit_array_str[i] != '0') {
      throw 1;
    }
  }

  *bit_array = ba;
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
    command_argument = atoi(argv[4]);
  }

  try {
    ParseBitArray(bit_array_str1, &bit_array1_);
    ParseBitArray(bit_array_str2, &bit_array2_);
  } catch (int e) {
    Help(argv[0], "Error: there is an incorrect bit array.\n\n");
    return message_;
  }

  BitArray ba;
  std::ostringstream s;

  if (command == "getsize") {
    s << bit_array1_.GetSize();
    message_ = s.str();
  } else if (command == "set") {
    try {
      bit_array1_.SetBit(command_argument);
      message_ = bit_array1_.ToString();
    } catch (std::string& e) {
      Help(argv[0], "Error: incorrect index.\n\n");
    }
  } else if (command == "clear") {
    try {
      bit_array1_.ClearBit(command_argument);
      message_ = bit_array1_.ToString();
    } catch (std::string& e) {
      Help(argv[0], "Error: incorrect index.\n\n");
    }
  } else if (command == "invert") {
    ba = ~bit_array1_;
    message_ = ba.ToString();
  } else if (command == "union") {
    ba = bit_array1_ | bit_array2_;
    message_ = ba.ToString();
  } else if (command == "inter") {
    ba = bit_array1_ & bit_array2_;
    message_ = ba.ToString();
  } else if (command == "xor") {
    ba = bit_array1_ ^ bit_array2_;
    message_ = ba.ToString();
  } else {
    Help(argv[0], "Error: incorrect command.\n");
  }

  return message_;
}
