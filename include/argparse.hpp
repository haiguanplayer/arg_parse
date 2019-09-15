#pragma once

// #include <any> cpp 17+
#include <string>
#include <map>
#include <vector>

namespace argparse {

class BaseAny {
public:
  virtual ~BaseAny() {}
};

template <class T>
class Any : public BaseAny {
public:

private:
  T any_;
};

class Exception {

};

class Parser {
public:
  Parser() = default;
  ~Parser() = default;
  void add_argument(std::string);
  void parse_args(int, std::vector<std::string>);
  void print_help();
  void print_invalid();


private:
  std::map<std::string, BaseAny *> arguments; 
};

class ArgParse {
public:
  ArgParse(std::string);
	void add_argument(std::string);
  void parse_args(int, std::vector<std::string>);
  void print_help();
  void print_invalid();
  ArgParse add_subparsers(std::string);

private:

  Parser add_parser();

  Parser *parser_;
  std::map<std::string, std::string> settings_;
};
} // namespace
