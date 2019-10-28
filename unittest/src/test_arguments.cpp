#include <cstdio>
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "argparse.hpp"

using namespace std;

TEST(sample, arguments) {
  argparse::ArgParse parser("empty");
  
  parser.add_argument("name");
  parser.add_argument("height");
  parser.add_argument("width");

  int argc = 4;
  vector<string> argv = {"",  "color", "3.6", "4.8"};
  parser.parse_args(argc, argv);
  cout << parser.get_value<std::string>("name") << "\n";
  cout << parser.get_value<float>("height") << "\n";
  cout << parser.get_value<float>("width") << "\n";
}
