#include <iostream>
#include "argparse.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  argparse::ArgParse parse("empty");
  parse.add_argument("name");
  parse.add_argument("height");
  parse.add_argument("width");
  parse.add_argument("channels");
  parse.add_argument("--style", 2);
  //parse.add_argument("point",2);
  //parse.add_argument("--format_name", 0, std::vector<std::string>({"bgr", "gray"}));
  parse.parse_args(argc, argv);
  cout << parse.get_value<std::string>("name") << "\n";
  cout << parse.get_value<float>("height") << "\n";
  cout << parse.get_value<float>("width") << "\n";
  cout << parse.get_value<int>("channels") << "\n";
  std::vector<int> style{};
  style =  parse.get_value<std::vector<int>>("--style");
  for (int st : style) {
   printf("style is %d\n", st);
  }
}
