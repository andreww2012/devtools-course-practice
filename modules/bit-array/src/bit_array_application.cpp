// Copyright 2017 Kazakov Andrew

#include "include/bit_array.h"
#include "include/bit_array_application.h"

#include <string>

Application::Application() {}

void Application::Help(const char* appname, const char* message = "") {
  message_ = "";
}

bool Application::ValidateNumberOfArguments(int argc, char** argv) {

}

std::string Application::operator()(int argc, char** argv) {

}
