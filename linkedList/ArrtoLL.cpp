#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;
  Node(int d, Node *n, Node *p) {
    data = d;
    next = n;
    prev = p;
  }
};

Node *ArrtoLL(int arr[]) {
  Node *temp = new Node(arr[0], nullptr, nullptr);
  Node *head = temp;
  Node *prev = temp;
  for (int i = 1; i < 4; i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

Node *reverseDLL(Node *head) {
  Node *newHead = nullptr;
  while (head) {
    Node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    newHead = head;
    head = temp;
  }
  return newHead;
}

int main() {
  int arr[4] = {1, 2, 3, 4};
  Node *head = ArrtoLL(arr);
  head = reverseDLL(head);
  Node *temp = head;
  while (temp) {
    cout << temp->data << endl;
    temp = temp->next;
  }
}
