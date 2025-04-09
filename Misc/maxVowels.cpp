#include <climits>
#include <iostream>
using namespace std;

int maxVowels(string s, int k) {
  int len = s.size();
  int currV{};
  int maxV = INT_MIN;
  int l{};
  int m{};

  for (int i = 0; m < k; i++) {
    m++;
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u') {
      currV++;
    }
  }
  if (currV > maxV) {
    maxV = currV;
  }

  while (m < len) {
    if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' ||
        s[l] == 'u') {
      currV--;
      l++;
    } else {
      l++;
    }
    if (s[m] == 'a' || s[m] == 'e' || s[m] == 'i' || s[m] == 'o' ||
        s[m] == 'u') {
      currV++;
      m++;
    } else {
      m++;
    }

    if (currV > maxV) {
      maxV = currV;
    }
  }
  return maxV;
}

int main(int argc, char *argv[]) {
  string str = "abciiidef";
  cout << maxVowels(str, 3);
  return 0;
}
