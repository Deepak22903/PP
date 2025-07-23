#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (auto &str : arr) {
    for (int i = 0; i + 2 < str.size();) {
      string sub = str.substr(i, 3);
      if (sub == "FFT" || sub == "NTT") {
        swap(str[i + 1], str[i + 2]);
        // move index back safely to recheck the area where swap happened
        if (i > 0)
          i--;
      } else {
        i++;
      }
    }
  }

  for (auto &val : arr) {
    cout << val << endl;
  }
}
