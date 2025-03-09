#include "io.h"

int main(int argc, char *argv[]) {
  int a{}, b{}, c{};
  a = userInput();
  b = userInput();
  c = a + b;
  writeAnswer(c);
  return 0;
}
