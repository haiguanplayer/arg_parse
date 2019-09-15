#include "argparse.hpp"
#include <iostream>

using namespace argparse;




Parser ArgParse::add_parser() {
  parser_ = new Parser();
}

ArgParse::ArgParse(std::string name) {
  parser_ = add_parser(name);
}

void ArgParse::add_argument(std::string name) {
  parser_->add_argument(name);
}

void ArgParse::parse_args(int argc, std::vector<std::string> argv) {
  parser_->parse_args(argc, argv);
}

ArgParse ArgParse::add_subparsers(std::string name) {
  return ArgParse(name);
}
