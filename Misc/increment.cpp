#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Incrementer {
public:
  vector<int> increment(vector<int> &digits) {
    vector<int> res(digits);
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      int sum = digits[i] + carry;
      res[i] = sum % 10;
      carry = sum / 10;
    }
    if (carry) {
      res.insert(res.begin(), carry);
    }
    return res;
  }
};

int main() {
  Incrementer inc;
  vector<int> digits = {7, 2, 8, 5, 0, 9, 1, 2, 9, 5, 3, 6, 6,
                        7, 3, 2, 8, 4, 3, 7, 9, 5, 7, 7, 4, 7,
                        4, 9, 4, 7, 0, 1, 1, 1, 7, 4, 0, 0, 6};
  vector<int> result = inc.increment(digits);
  cout << "Result: ";
  for (int digit : result) {
    cout << digit << " ";
  }
  cout << endl;

  return 0;
}
