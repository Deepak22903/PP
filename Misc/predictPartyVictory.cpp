#include <iostream>
#include <vector>
using namespace std;

string predictPartyVictory(string senate) {
  int len = senate.size();
  int dit{}, rit{};
  vector<bool> dirty(len, 0);
  int i{};
loop:
  i = 0;
  dit = 0;
  rit = 0;
  while (i < len) {
    if (dirty[i] == 1) {
      i++;
      continue;
    }
    bool banned = false;
    if (senate[i] == 'R') {
      for (int k = 1; k < len; k++) {
        int idx = (i + k) % len;
        if (senate[idx] == 'D' && dirty[idx] == 0) {
          dirty[idx] = 1;
          banned = true;
          break;
        }
      }
      if (!banned)
        return "Radiant";
    } else {
      for (int k = 1; k < len; k++) {
        int idx = (i + k) % len;
        if (senate[idx] == 'R' && dirty[idx] == 0) {
          dirty[idx] = 1;
          banned = true;
          break;
        }
      }
      if (!banned)
        return "Dire";
    }
    i++;
  }

  int index;
  bool foundZero = false;
  for (int k = 0; k < len; k++) {
    if (dirty[k] == 0 && !foundZero) {
      foundZero = true;
      index = k;

    } else if (dirty[k] == 0 && foundZero) {
      goto loop;
    }
  }

  if (senate[index] == 'R')
    return "Radiant";
  else
    return "Dire";

  return "";
}

int main(int argc, char *argv[]) {
  string s = "DRRDRDRDRDDRDRDR";
  cout << predictPartyVictory(s) << endl;
  return 0;
}
