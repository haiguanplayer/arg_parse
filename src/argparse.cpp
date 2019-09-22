#include "argparse.hpp"
#include <iostream>
#include <typeinfo>

using namespace argparse;


Argument::Argument(std::string name, int nargs, std::vector<std::string> choices, std::string help) {
  name_ = name;
  nargs_ = nargs;
  std::copy(choices.begin(), choices.end(), std::back_inserter(choices_));
  help_ = help;
  value_ = {};
}

void Argument::add_value(std::string value) {
  value_.push_back(value);
}
void Parser::add_argument(std::string name, int nargs, std::vector<std::string> choices, std::string help) {
  Argument argument(name, nargs, choices, help);
  arg_name_.push_back(name);
  arguments_[name] = argument;
}

void Parser::parse_args(int argc, std::vector<std::string> argv) {
  int cnt = 0;
  for (int i = 1; i < argc;) {
    if (arg_name_[cnt][0] != '-') { // positional arguments
      if (argc - i + 1 < arguments_[arg_name_[cnt]].nargs_) {
        printf("parse error positional arguments.");
        break;
      }
      for (int j = 0; j < arguments_[arg_name_[cnt]].nargs_; ++j) {
        arguments_[arg_name_[cnt]].add_value(argv[i++]);
      }
      ++cnt;
    } else { // optional arguments
printf("??%d %d %s %s\n", i, cnt, arg_name_[cnt].c_str(), argv[i].c_str());
      while (cnt < arg_name_.size() && arg_name_[cnt] != argv[i]) { ++cnt;printf("cnt %d\n", cnt); }
      if (cnt >= arg_name_.size()) {
        printf("parse error optional arguments.");
        break;
      }
      for (int j = 0; j < arguments_[arg_name_[cnt]].nargs_; ++j) {
printf("%s\n", argv[i+1].c_str());
        arguments_[arg_name_[cnt]].add_value(argv[++i]);
printf("...\n");
      }
      ++i;
      ++cnt;
    }
    
  }  
}

Parser* ArgParse::add_parser() {
  return new Parser();
}

ArgParse::ArgParse(std::string name) {
  settings_["name"] = name;
  parser_ = add_parser();
}

ArgParse::~ArgParse() {
  delete parser_;
}

void ArgParse::add_argument(std::string name, int nargs, std::vector<std::string> choices, std::string help) {
  parser_->add_argument(name, nargs, choices, help);
}

void ArgParse::parse_args(int argc, char **argv) {
  std::vector<std::string> arg_vec{};
  for (int i = 0; i < argc; ++i) {
   std::string tmp_arg = argv[i];
    arg_vec.push_back(tmp_arg);
  }
  parser_->parse_args(argc, arg_vec);
}

ArgParse ArgParse::add_subparsers(std::string name) {
  return ArgParse(name);
}
