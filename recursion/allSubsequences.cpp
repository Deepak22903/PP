#include <iostream>
#include <vector>
using namespace std;

void subs(vector<int> &arr, int i, vector<int> sub, int n) {
  if (i >= n) {
    for (int val : sub) {
      cout << val << " ";
    }
    cout << endl;
    return;
  }
  sub.push_back(arr[i]);
  subs(arr, i + 1, sub, n);
  sub.pop_back();
  subs(arr, i + 1, sub, n);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 2};
  subs(arr, 0, {}, arr.size());
  return 0;
}
