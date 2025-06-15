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
    // No implementation
    if (!head || !head->next || !head->next->next)
      return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    while (even && even->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    odd->next = evenHead;
    return head;
  }
};

// Helper function to create a linked list from a vector
ListNode *createList(const vector<int> &vals) {
  if (vals.empty())
    return nullptr;
  ListNode *head = new ListNode(vals[0]);
  ListNode *curr = head;
  for (int i = 1; i < vals.size(); ++i) {
    curr->next = new ListNode(vals[i]);
    curr = curr->next;
  }
  return head;
}

// Helper function to print a linked list
void printList(ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> vals = {1, 2, 3, 4, 5};
  ListNode *head = createList(vals);

  cout << "Original list: ";
  printList(head);

  ListNode *result = sol.oddEvenList(head);

  cout << "After calling oddEvenList: ";
  printList(result);

  return 0;
}
