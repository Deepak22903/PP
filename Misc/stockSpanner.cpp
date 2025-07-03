#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class StockSpanner {
public:
  StockSpanner() {
    // Constructor implementation goes here
  }

  stack<pair<int, int>> st;
  int next(int price) {
    // Method implementation goes here

    int span = 1;
    while (!st.empty() && st.top().first <= price) {
      span += st.top().second;
      st.pop();
    }
    st.push({price, span});
    return st.top().second;
  }
};

int main() {
  StockSpanner *obj = new StockSpanner();
  vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

  cout << "Spans: ";
  for (int price : prices) {
    int span = obj->next(price);
    cout << span << " ";
  }
  cout << endl;

  delete obj;
  return 0;
}
