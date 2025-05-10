#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  stack<string> ss;
  void rmWhite(string &s) {
    while (!s.empty() && s[0] == ' ')
      s.erase(s.begin());
  }
  int lengthOfLastWord(std::string s) {
    // Implementation goes here
    while (!s.empty()) {
      rmWhite(s);
      if (s.empty())
        break;
      int start = 0;
      int count{};
      int i{};
      while (i < s.size() && s[i] != ' ') {
        count++;
        i++;
      }
      string word = s.substr(start, count);
      s.erase(s.begin(), s.begin() + count);
      ss.push(word);
    }

    return ss.top().size();
  }
};

int main() {
  Solution sol;
  std::string input = "h";
  int result = sol.lengthOfLastWord(input);
  std::cout << "Length of last word: " << result << std::endl;
  return 0;
}
