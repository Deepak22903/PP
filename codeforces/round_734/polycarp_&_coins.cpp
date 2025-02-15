#include <iostream>
#include <vector>
using namespace std;

void coins(int total) {
  int ones = total / 3;
  int twos = ones;
  int r = total % 3;
  if (r == 1) {
    ones++;
  } else if (r == 2) {
    twos++;
  }
  cout << ones << " " << twos << endl;
}

int main() {
  int t;
  cin >> t;
  vector<int> input(t);
  for (int i = 0; i < t; i++) {
    cin >> input[i];
  }
  for (int i = 0; i < t; i++) {
    coins(input[i]);
  }
  return 0;
}
