#include <iostream>
using namespace std;
int userInput() {
  cout << "Enter a Number: ";
  int input{};
  cin >> input;
  return input;
}

void writeAnswer(int num) { cout << "\n Answer: " << num << endl; }
