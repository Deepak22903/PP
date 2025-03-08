#include <iostream>
#include <ostream>
using std::cin;

int main(int argc, char *argv[]) {
  std::string str{};
  while ((cin >> str)) {
    std::cout << str;
  }
  return 0;
}
