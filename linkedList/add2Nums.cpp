#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int d, ListNode *n) {
    val = d;
    next = n;
  }
};

ListNode *reverseList(ListNode *head) {
  if (head == NULL || head->next == NULL)
    return head;
  ListNode *curr = head;
  ListNode *next = head->next;
  ListNode *prev = nullptr;
  while (next) {
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
  }
  curr->next = prev;
  return curr;
}

ListNode *add(ListNode *l1, ListNode *l2) {
  l1 = reverseList(l1);
  l2 = reverseList(l2);
  int carry = 0;
  ListNode *res = new ListNode(0, nullptr);
  ListNode *curr = res;

  while (l1 && l2) {
    int sum = (l1->val + l2->val + carry) % 10;
    carry = (l1->val + l2->val + carry) / 10;
    curr->next = new ListNode(sum, nullptr);
    curr = curr->next;
    l1 = l1->next;
    l2 = l2->next;
  }
  while (l1) {
    int sum = (l1->val + carry) % 10;
    carry = (l1->val + carry) / 10;
    curr->next = new ListNode(sum, nullptr);
    curr = curr->next;
    l1 = l1->next;
  }
  while (l2) {
    int sum = (l2->val + carry) % 10;
    carry = (l2->val + carry) / 10;
    curr->next = new ListNode(sum, nullptr);
    curr = curr->next;
    l2 = l2->next;
  }
  if (carry)
    curr->next = new ListNode(carry, nullptr);
  ListNode *temp = res;
  res = res->next;
  temp->next = nullptr;
  return reverseList(res);
}

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3, nullptr)));
  ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4, nullptr)));
  ListNode *res = add(l1, l2);
  while (res) {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}
