#include <iostream>
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
  ListNode *oddEvenList(ListNode *head) {
    // Your implementation here
    if (!head) {
      return nullptr;
    } else if (head->next == nullptr) {
      return head;
    }
    ListNode *oddHead = nullptr;
    ListNode *evenHead = nullptr;
    ListNode *curr = head;
    ListNode *oddCurr = nullptr;
    ListNode *evenCurr = nullptr;
    int currIndex{1};
    cout << endl;
    while (curr) {
      if ((currIndex % 2) != 0) {
        if (!oddHead) {
          oddHead = curr;
          oddCurr = oddHead;
        } else {
          oddCurr->next = curr;
          oddCurr = oddCurr->next;
        }
      } else {
        if (!evenHead) {
          evenHead = curr;
          evenCurr = evenHead;
        } else {
          evenCurr->next = curr;
          evenCurr = evenCurr->next;
        }
      }
      curr = curr->next;
      currIndex++;
    }
    evenCurr->next = nullptr;
    oddCurr->next = evenHead;
    ListNode *temp = oddHead;
    while (temp) {
      cout << temp->val << endl;
      temp = temp->next;
    }
    return oddHead;
  }
};

int main() {
  vector<int> vals = {2, 1, 3, 5, 6, 4, 7}; // Example input
  ListNode *head = new ListNode(vals[0]);
  ListNode *curr = head;
  for (int i = 1; i < vals.size(); ++i) {
    curr->next = new ListNode(vals[i]);
    curr = curr->next;
  }

  Solution sol;
  ListNode *result = sol.oddEvenList(head);

  // Output result list
  // while (result) {
  //   cout << result->val << " ";
  //   result = result->next;
  // }
  // cout << endl;

  return 0;
}
