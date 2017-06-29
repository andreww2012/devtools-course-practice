// Copyright 2017 Kazakov Andrew

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <iostream>

#include "include/bit_array_application.h"

using ::testing::internal::RE;

class ApplicationTest: public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("appname");
    for (size_t i = 0; i < args_.size(); ++i) {
        options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  BitArrayApp app_;
  std::string output_;
};

TEST_F(ApplicationTest, app_prints_help_without_arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is a bit array application.*");
}

TEST_F(ApplicationTest, app_checks_amount_of_arguments) {
  std::vector<std::string> args = {"test", "test"};

  Act(args);

  Assert("Error: should be 3 or 4 arguments.*");
}

TEST_F(ApplicationTest, app_checks_incorrect_first_bit_array) {
  std::vector<std::string> args = {"incorrect", "110001", "getsize"};

  Act(args);

  Assert("Error: there is an incorrect bit array.*");
}

TEST_F(ApplicationTest, app_checks_incorrect_second_bit_array) {
  std::vector<std::string> args = {"110001", "incorrect", "getsize"};

  Act(args);

  Assert("Error: there is an incorrect bit array.*");
}

TEST_F(ApplicationTest, app_checks_incorrect_command) {
  std::vector<std::string> args = {"110001", "11100", "unknowncmd"};

  Act(args);

  Assert("Error: incorrect command.*");
}

TEST_F(ApplicationTest, app_checks_set_command_needs_bit_number) {
  std::vector<std::string> args = {"110001", "11100", "set"};

  Act(args);

  Assert("Error: incorrect index.*");
}

TEST_F(ApplicationTest, app_checks_clear_command_needs_bit_number) {
  std::vector<std::string> args = {"110001", "11100", "clear"};

  Act(args);

  Assert("Error: incorrect index.*");
}

TEST_F(ApplicationTest, app_checks_bit_number_is_negative_in_set_command) {
  std::vector<std::string> args = {"110001", "11100", "set", "-2"};

  Act(args);

  Assert("Error: incorrect index.*");
}

TEST_F(ApplicationTest, app_checks_bit_number_is_negative_in_clear_command) {
  std::vector<std::string> args = {"110001", "11100", "clear", "-3"};

  Act(args);

  Assert("Error: incorrect index.*");
}

TEST_F(ApplicationTest, app_checks_bit_number_is_incorrect_in_set_command) {
  std::vector<std::string> args = {"110001", "11100", "set", "200"};

  Act(args);

  Assert("Error: incorrect index.*");
}

TEST_F(ApplicationTest, app_checks_bit_number_is_incorrect_in_clear_command) {
  std::vector<std::string> args = {"110001", "11100", "clear", "133"};

  Act(args);

  Assert("Error: incorrect index.*");
}
