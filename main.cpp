#include <iostream>
#include "argparse.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  argparse::ArgParse parse("empty");
  parse.add_argument(argv[1]);
  parse.get_argument();
  printf("%d\n", argc);
  printf("sadadsa\n");
}
