#include <cstdlib>
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteMiddle(ListNode *head) {
    int len{};
    ListNode *temp = head;
    while (temp) {
      len++;
      temp = temp->next;
    }
    if (len == 1) {
      return nullptr;
    } else if (len == 2) {
      ListNode *temp = head->next;
      head->next = nullptr;
      return head;
    } else {
      int target = len / 2;
      ListNode *prev = nullptr;
      ListNode *curr = head;
      int index{};

      while (index != target) {
        index++;
        prev = curr;
        curr = curr->next;
      }
      prev->next = curr->next;
    }

    return head;
  }
};

int main() {
  // Create the list: 1 -> 2 -> 3 -> 4 -> 5
  ListNode *head = new ListNode(1);

  Solution sol;
  ListNode *result = sol.deleteMiddle(head);

  // Print the resulting list
  while (result) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << std::endl;

  return 0;
}
