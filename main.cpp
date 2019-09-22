#include <iostream>
#include "argparse.hpp"

using namespace std;

int main(int argc, char *argv[]) {
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
  //parse.add_argument("channels");
  //parse.add_argument("--style", 2);
  //parse.add_argument("point",2);
  //parse.add_argument("--format_name", 0, std::vector<std::string>({"bgr", "gray"}));
  sub_parse.parse_args(argc, argv);
  cout << sub_parse.get_value<std::string>("name") << "\n";
  cout << sub_parse.get_value<float>("height") << "\n";
  cout << sub_parse.get_value<float>("width") << "\n";
  //cout << parse.get_value<int>("channels") << "\n";
  //std::vector<int> style{};
  //style =  parse.get_value<std::vector<int>>("--style");
  //for (int st : style) {
  // printf("style is %d\n", st);
  //}
}
