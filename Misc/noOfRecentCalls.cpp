#include <iostream>
#include <vector>
using namespace std;
class RecentCounter {
public:
  RecentCounter() {}
  vector<int> arr;
  int ping(int t) {
    int res{};
    arr.push_back(t);
    for (int val : arr) {
      if (val >= (t - 3000) && val <= t)
        res++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {

  RecentCounter *obj = new RecentCounter();
  int param_1 = obj->ping(1);
  cout << param_1 << endl;
  param_1 = obj->ping(100);
  cout << param_1 << endl;
  param_1 = obj->ping(3001);
  cout << param_1 << endl;
  param_1 = obj->ping(3002);
  cout << param_1 << endl;
  return 0;
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
