#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < minPrice) {
        minPrice = prices[i];
      } else {
        maxProfit = max(maxProfit, prices[i] - minPrice);
      }
    }
    return maxProfit;
  }
  // int maxProfit(vector<int> &prices) {
  //   // Solution goes here
  //   int maxP = 0;
  //   int currMax{};
  //   int index{};
  //   for (int i = 0; i < prices.size() - 1; i++) {
  //     if (i < index) {
  //       if (currMax < prices[i] || currMax == prices[i]) {
  //         continue;
  //       } else {
  //         maxP = max(maxP, currMax - prices[i]);
  //       }
  //     } else {
  //       auto it = max_element(prices.begin() + i + 1, prices.end());
  //       currMax = *it;
  //       index = distance(prices.begin(), it);
  //       i--;
  //     }
  //   }
  //   return maxP;
  // }
};

int main() {
  vector<int> prices = {1, 2};

  Solution sol;
  int profit = sol.maxProfit(prices);

  // Output the result
  cout << "Maximum profit: " << profit << endl;

  return 0;
}
