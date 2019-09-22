#pragma once

// #include <any> cpp 17+
#include <string>
#include <map>
#include <vector>
#include <typeinfo>
#include <algorithm>

namespace argparse {

//class BaseAny {
//public:
//  virtual ~BaseAny() {}
//};
//
//template <class T>
//class Any : public BaseAny {
//public:
//
//private:
//  T any_;
//};
//enum class Type {
//  Int = 0,
//  Float = 1,
//  Double = 2,
//  String = 3
//};

class Exception {

};

class Argument {
public:
  Argument() = default;
  Argument(std::string, int, std::vector<std::string>, std::string);
  void add_value(std::string);
  std::string get_argument();

  std::string name_;
  std::vector<std::string> value_;
  int nargs_;
  std::vector<std::string> choices_;
  std::string help_;
};

class Parser {
public:
  Parser() = default;
  ~Parser() = default;
	void add_argument(std::string name = "", int nargs = 1, std::vector<std::string> choices = {}, std::string help = "");
  void parse_args(int, std::vector<std::string>);
  template <typename type>
  type get_value(std::string key); 
  void print_help();
  void print_invalid();

private:
  
  std::vector<std::string> arg_name_;
  std::map<std::string, Argument> arguments_; 
};

class ArgParse {
public:
  ArgParse(std::string);
  ~ArgParse();
	void add_argument(std::string name = "", int nargs = 1, std::vector<std::string> choices = {}, std::string help = "");
  void parse_args(int, char **);
  template <typename type>
  type get_value(std::string key) {
    return parser_[parser_name_]->get_value<type>(key);
  }
  void print_help();
  void print_invalid();
  ArgParse add_subparsers(std::string);
  Parser* add_parser(std::string);

private:

  std::string parser_name_;
  std::map<std::string, Parser *> parser_;
  std::map<std::string, std::string> settings_;
};
} // namespace
