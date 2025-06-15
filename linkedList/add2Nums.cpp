#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int d, Node *n) {
    data = d;
    next = n;
  }
};

Node *reverseList(Node *head) {
  if (head == NULL || head->next == NULL)
    return head;
  Node *curr = head;
  Node *next = head->next;
  Node *prev = nullptr;
  while (next) {
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
  }
  return curr;
}

// Node *add(Node *l1, Node *l2) {}

int main(int argc, char *argv[]) {
  Node *l1 = new Node(2, new Node(4, new Node(6, nullptr)));
  Node *l2 = new Node(3, new Node(8, new Node(7, nullptr)));
  Node *res = reverseList(l1);
  while (res) {
    cout << res->data << " ";
    res = res->next;
  }
  // Node *res = add(l1, l2);
  return 0;
}
