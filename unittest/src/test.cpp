#include <cstdio>
#include <iostream>
#include "gtest/gtest.h"
#include "argparse.hpp"
#include "arg.h"

using namespace std;

TEST(sample, first) {
  argparse::ArgParse parse("empty");
  argparse::ArgParse sub_parse = parse.add_subparsers("sub");
  argparse::Parser* sub1 = sub_parse.add_parser("sub1");
  argparse::Parser* sub2 = sub_parse.add_parser("sub2");
  
  
  sub1->add_argument("name");
  sub1->add_argument("height");
  sub1->add_argument("width");
  sub2->add_argument("name");
  sub2->add_argument("height");
  sub2->add_argument("width");

  int argc = 5;
  char argv[][] = {"", "bgr", "9.1", "5.3"};
  sub_parse.parse_args(argc, argv);
  cout << sub_parse.get_value<std::string>("name") << "\n";
  cout << sub_parse.get_value<float>("height") << "\n";
  cout << sub_parse.get_value<float>("width") << "\n";
}
