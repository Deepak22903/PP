#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int maxS = INT_MIN;
void subs(vector<int> &arr, int i, vector<int> sub, int n, int sum,
          int target) {
  if (i == n) {
    if (sum == target) {
      int n = sub.size();
      maxS = max(maxS, n);
    }
    return;
  }

  sum += arr[i];
  sub.push_back(arr[i]);
  subs(arr, i + 1, sub, n, sum, target);
  sum -= arr[i];
  sub.pop_back();

  subs(arr, i + 1, sub, n, sum, target);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 1, 2};
  int target = 2;
  subs(arr, 0, {}, arr.size(), 0, target);
  cout << maxS << endl;
  return 0;
}
