#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int exer() {
  int en{};
  int n{};
  vector<int> ex;
  cin >> en;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp{};
    cin >> temp;
    ex.push_back(temp);
  }
  int res{};
  sort(ex.begin(), ex.end(), greater<int>());
  for (int val : ex) {
    if ((val * 2) <= en) {
      en = en - (val * 2);
      res = res + 2;
    } else if (val > en) {
      continue;
    } else if (val <= en) {
      en = en - val;
      res = res + 1;
    }
    if (en == 0) {
      return res;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  cout << exer() << endl;
  return 0;
}
