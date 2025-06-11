#include <iostream>
using namespace std;

bool checkPal(string &s, int l, int r) {
  if (l >= r)
    return true;
  if (s[l] != s[r])
    return false;
  return checkPal(s, l + 1, r - 1);
}

int main(int argc, char *argv[]) {
  string s = "madar";
  cout << checkPal(s, 0, s.size() - 1) << endl;
  return 0;
}
