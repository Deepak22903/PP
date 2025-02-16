#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  bool res = strcmp(s.c_str(), t.c_str());
  return !res;
}
int main() {
  string s = "racecar";
  string t = "carrace";
  bool res = isAnagram(s, t);
  if (!res) {
    cout << "true";
  } else {
    cout << "false";
  }
}
