#include "argparse.hpp"
#include <iostream>
#include <typeinfo>


namespace argparse{

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
      while (cnt < arg_name_.size() && arg_name_[cnt] != argv[i]) { ++cnt;}
      if (cnt >= arg_name_.size()) {
        printf("parse error optional arguments.");
        break;
      }
      for (int j = 0; j < arguments_[arg_name_[cnt]].nargs_; ++j) {
        arguments_[arg_name_[cnt]].add_value(argv[++i]);
      }
      ++i;
      ++cnt;
    }
    
  }  
}

// std::string value
template <>
std::string Parser::get_value<std::string>(std::string key) {
    return arguments_[key].value_[0];
}

// bool value
template <>
bool Parser::get_value<bool>(std::string key) {
    return (bool)std::atoi(arguments_[key].value_[0].c_str());
}

// int value 
template <>
int Parser::get_value<int>(std::string key) {
    return std::atoi(arguments_[key].value_[0].c_str());
}

// float value
template <>
float Parser::get_value<float>(std::string key) {
    return (float)std::atof(arguments_[key].value_[0].c_str());
}

// double value
template <>
double Parser::get_value<double>(std::string key) {
    return std::atof(arguments_[key].value_[0].c_str());
}

// std::vector<std::string> value
template <>
std::vector<std::string> Parser::get_value<std::vector<std::string>>(std::string key) {
  return arguments_[key].value_;
}

// std::vector<bool> value
template <>
std::vector<bool> Parser::get_value<std::vector<bool>>(std::string key) {
  std::vector<bool> res;
  std::transform(arguments_[key].value_.begin(), arguments_[key].value_.end(), std::back_inserter(res), [](const std::string &x) { return (bool)std::atoi(x.c_str()); });
  return res;
}

// std::vector<int> value
template <>
std::vector<int> Parser::get_value<std::vector<int>>(std::string key) {
  std::vector<int> res;
  std::transform(arguments_[key].value_.begin(), arguments_[key].value_.end(), std::back_inserter(res), [](const std::string &x) { return std::atoi(x.c_str()); });
  return res;
}

// std::vector<float> value
template <>
std::vector<float> Parser::get_value<std::vector<float>>(std::string key) {
  std::vector<float> res;
  std::transform(arguments_[key].value_.begin(), arguments_[key].value_.end(), std::back_inserter(res), [](const std::string &x) { return (float)std::atof(x.c_str()); });
  return res;
}
// std::vector<double> value
template <>
std::vector<double> Parser::get_value<std::vector<double>>(std::string key) {
  std::vector<double> res;
  std::transform(arguments_[key].value_.begin(), arguments_[key].value_.end(), std::back_inserter(res), [](const std::string &x) { return std::atof(x.c_str()); });
  return res;
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
}
