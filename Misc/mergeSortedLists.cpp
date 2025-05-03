#include <iostream>
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // Implementation goes here
    ListNode *res = nullptr;
    ListNode *curr = nullptr;
    ListNode *i = list1;
    ListNode *j = list2;

    if (i->val < j->val) {
      curr = new ListNode(i->val, nullptr);
      res = curr;
      i = i->next;
    } else if (i->val > j->val) {
      curr = new ListNode(j->val, nullptr);
      j = j->next;
      res = curr;
    } else {
      curr = new ListNode(i->val, nullptr);
      curr->next = new ListNode(j->val, nullptr);
      res = curr;
      curr = curr->next;
      j = j->next;
      i = i->next;
    }

    while (i && j) {
      if (i->val < j->val) {
        curr->next = new ListNode(i->val, nullptr);
        i = i->next;
      } else if (i->val > j->val) {
        curr->next = new ListNode(j->val, nullptr);
        j = j->next;
      } else {
        curr->next = new ListNode(i->val, nullptr);
        curr->next->next = new ListNode(j->val, nullptr);
        curr = curr->next;
        j = j->next;
        i = i->next;
      }
    }
    curr = curr->next;
    ListNode *temp = !i ? j : i;
    curr->next = temp;

    while (res) {
      cout << res->val << endl;
      res = res->next;
    }

    return nullptr;
  }
};

int main() {
  // Example usage
  ListNode *list1 = new ListNode(1, new ListNode(3, new ListNode(5)));
  ListNode *list2 = new ListNode(2, new ListNode(4, new ListNode(6)));

  Solution sol;
  ListNode *mergedList = sol.mergeTwoLists(list1, list2);

  // Print merged list (if implemented)
  // ListNode *current = mergedList;
  // while (current != nullptr) {
  //   cout << current->val << " ";
  //   current = current->next;
  // }
  // cout << endl;

  // Free memory if needed (not shown)

  return 0;
}
