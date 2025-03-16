#include <iostream>

using namespace std;

int foo(int a, int b) { return a + b; }

int main(int argc, char *argv[]) {
  int a, b;
  a = 2;
  b = 3;
  int c = foo(a, b);
  if (c > 10) {
    cout << "Hello" << endl;
  } else {
    cout << "Byee" << endl;
  }
  return 0;
}
