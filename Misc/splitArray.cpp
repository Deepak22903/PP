#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPrime(long long n) {
    if (n == 0 || n == 1)
      return false;
    if (n == 2 || n == 3)
      return true;
    if (n % 2 == 0 || n % 3 == 0)
      return false;
    for (int i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0) {
        return false;
      }
    }
    return true;
  }
  long long splitArray(vector<int> &nums) {
    // Your implementation here
    long long total = 0;
    for (auto val : nums)
      total += val;

    long long primeSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (isPrime(i))
        primeSum += nums[i];
    }
    long long nonPrimeSum = total - primeSum;

    return abs(primeSum - nonPrimeSum);
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-1, 5, 7, 0};
  long long result = sol.splitArray(nums);
  cout << "Result: " << result << endl;
  return 0;
}
