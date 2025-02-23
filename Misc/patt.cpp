#include <iostream>
#include <stack>
using namespace std;

stack<char> cs;
stack<int> is;

string dupes(string input) {
  for (int i = 0; i < input.size(); i++) {

    if (input[i] == '[') {

    } else if (input[i] == ']') {
    }

    else if constexpr (is_same_v<decltype(input[i]), char>) {
    } else if (input[i] == '[') {
    }
  }
}

int main(int argc, char *argv[]) {
  string input = "3[a2[c]]";
  string res = dupes(input);

  return 0;
}
