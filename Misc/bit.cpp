#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int i{};
  int n = 69;
  while (n > pow(2, i))
    i++;
  if (n == pow(2, i)) {
    cout << i << "\n";
  } else {
    cout << i - 1 << endl;
  }

  return 0;
}
