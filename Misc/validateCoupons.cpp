#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> validateCoupons(vector<string> &code,
                                 vector<string> &businessLine,
                                 vector<bool> &isActive) {
    set<string> cat;
    cat.insert("electronics");
    cat.insert("grocery");
    cat.insert("pharmacy");
    cat.insert("restaurant");
    vector<string> elec, gro, phar, rest;
    vector<string> res;
    for (int i = 0; i < code.size(); i++) {
      bool isFalse = false;
      string currCode = code[i];
      if (currCode.empty())
        isFalse = true;
      if (!isFalse) {
        for (int j = 0; j < currCode.size(); j++) {
          if (isalnum(currCode[j]) || currCode[j] == '_')
            continue;
          else
            isFalse = true;
          break;
        }
      }
      if (!isFalse) {
        if (cat.find(businessLine[i]) == cat.end())
          isFalse = true;
      }
      if (!isFalse) {
        if (!isActive[i])
          isFalse = true;
      }
      if (!isFalse) {
        if (businessLine[i] == "grocery")
          gro.push_back(code[i]);
        else if (businessLine[i] == "restaurant")
          rest.push_back(code[i]);
        else if (businessLine[i] == "pharmacy")
          phar.push_back(code[i]);
        else if (businessLine[i] == "electronics")
          elec.push_back(code[i]);
      }
    }
    sort(elec.begin(), elec.end());
    sort(phar.begin(), phar.end());
    sort(gro.begin(), gro.end());
    sort(rest.begin(), rest.end());
    res.insert(res.end(), elec.begin(), elec.end());
    res.insert(res.end(), gro.begin(), gro.end());
    res.insert(res.end(), phar.begin(), phar.end());
    res.insert(res.end(), rest.begin(), rest.end());
    return res;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  vector<string> code1 = {"SAVE20", "", "PHARMA5", "SAVE@20"};
  vector<string> businessLine1 = {"restaurant", "grocery", "pharmacy",
                                  "restaurant"};
  vector<bool> isActive1 = {true, true, true, true};

  vector<string> result1 = sol.validateCoupons(code1, businessLine1, isActive1);
  cout << "Output 1:\n";
  for (auto &c : result1)
    cout << c << " ";
  cout << "\nExpected: PHARMA5 SAVE20\n\n";

  // Test Case 2
  vector<string> code2 = {"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"};
  vector<string> businessLine2 = {"grocery", "electronics", "invalid"};
  vector<bool> isActive2 = {false, true, true};

  vector<string> result2 = sol.validateCoupons(code2, businessLine2, isActive2);
  cout << "Output 2:\n";
  for (auto &c : result2)
    cout << c << " ";
  cout << "\nExpected: ELECTRONICS_50\n";

  return 0;
}
