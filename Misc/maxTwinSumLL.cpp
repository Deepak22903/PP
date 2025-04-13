
#include <climits>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int pairSum(ListNode *head) {
    ListNode *temp = head;
    int maxSum = INT_MIN;
    int len{};
    while (temp) {
      len++;
      temp = temp->next;
    }
    unordered_map<int, int> map(len / 2);
    temp = head;
    int i{};
    for (; i < len / 2; i++) {
      map[i] = temp->val;
      temp = temp->next;
    }

    while (temp) {
      int sum{};
      auto it = map.find(len - 1 - i);
      sum = temp->val + it->second;
      if (sum > maxSum) {
        maxSum = sum;
      }
      i++;
      temp = temp->next;
    }

    return maxSum;
  }
};

int main() {
  // Sample list: [1, 2, 3, 4]
  // ListNode *node4 = new ListNode(4);
  // ListNode *node3 = new ListNode(3, node4);
  ListNode *node2 = new ListNode(2);
  ListNode *node1 = new ListNode(1, node2);

  Solution sol;
  int result = sol.pairSum(node1);
  cout << "Result: " << result << endl;

  // Clean up
  delete node1;
  delete node2;
  // delete node3;
  // delete node4;

  return 0;
}
