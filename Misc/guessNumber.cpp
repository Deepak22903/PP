#include <iostream>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *                1 if num is lower than the picked number
 *                otherwise return 0
 */
int guess(int num);

// You can change this pickedNumber for testing
int pickedNumber = 1702766719;

int guess(int num) {
  if (num > pickedNumber)
    return -1;
  if (num < pickedNumber)
    return 1;
  return 0;
}

class Solution {
public:
  int guessNumber(int n);
};

int Solution::guessNumber(int n) {
  long long start = 1;
  long long end = n;
  if (n == 1) {
    return 1;
  }
  long long mid{};
  do {
    mid = (start + end) / 2;
    if (guess(mid) == 0) {
      return mid;
    } else if (guess(mid) == 1) {
      start = mid + 1;
    } else if (guess(mid) == -1) {
      end = mid - 1;
    }
  } while (mid);
  return -1;
}

int main() {
  Solution solution;
  int n;
  cout << "Enter the upper limit (n): ";
  cin >> n;

  int result = solution.guessNumber(n);
  cout << "Guessed number is: " << result << endl;

  return 0;
}
