#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    if (x == 0)
      return 0;
    int s = 1;
    int e = x;
    int m{};
    while (s <= e) {
      m = s + (e - s) / 2;
      if (pow(m, 2) == x) {
        return m;
      } else if (pow(m, 2) < x) {
        s = m + 1;
      } else {
        e = m - 1;
      }
    }
    return e;
  }
  // int mySqrt(int x) {
  //   // Implementation goes here
  //   int i{};
  //   for (; pow(i, 2) < x; i++)
  //     ;
  //   if (pow(i, 2) == x) {
  //     return i;
  //   } else {
  //     return i - 1;
  //   }
  // }
};

int main() {
  Solution sol;
  int x = 8;
  int result = sol.mySqrt(x);
  cout << "The square root of " << x << " is " << result << endl;
  return 0;
}
