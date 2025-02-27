#include <iostream>

using namespace std;

int userInput() {
  int a{};
  cout << "Enter an Integer: ";
  cin >> a;
  return a;
}

int toDouble(int num) { return 2 * num; }

int main(int argc, char *argv[]) {
  int para{userInput()};
  cout << "double of " << para << " is " << toDouble(para) << endl;
  return 0;
}
