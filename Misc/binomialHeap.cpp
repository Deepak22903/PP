#include <iostream>

using namespace std;

struct Node {
  Node *parent;
  Node *child;
  Node *sibling;
  int key;
  int degree;
  Node(int key)
      : key(key), parent(nullptr), child(nullptr), sibling(nullptr),
        degree(0) {};
};

class binomialHeap {
private:
  Node *head;
  Node *mergeHeaps(Node *h1, Node *h2) {
    if (!h1)
      return h2;
    if (!h2)
      return h1;

    Node *head = nullptr;
    Node *tail = nullptr;

    if (h1->degree <= h2->degree) {
      head = h1;
      h1 = h1->sibling;
    } else {
      head = h2;
      h2 = h2->sibling;
    }
    tail = head;

    while (h1 && h2) {
      if (h1->degree <= h2->degree) {
        tail->sibling = h1;
        h1 = h1->sibling;
      } else {
        tail->sibling = h2;
        h2 = h2->sibling;
      }
      tail = tail->sibling;
    }
    if (h1) {
      tail->sibling = h1;
    }
    if (h2) {
      tail->sibling = h2;
    }
    return head;
  }

  void linkNodes(Node *curr, Node *next) {
    next->sibling = curr->child;
    curr->child = next;
    next->parent = curr;
    curr->degree++;
  }

  Node *unionHeap(Node *h1, Node *h2) {
    Node *nh = mergeHeaps(h1, h2);
    if (!nh)
      return nullptr;
    Node *prev = nullptr;
    Node *curr = nh;
    Node *next = nh->sibling;

    while (next) {
      if (curr->degree != next->degree ||
          (next->sibling && curr->degree == next->sibling->degree)) {
        prev = curr;
        curr = next;
      } else {
        if (curr->key <= next->key) {
          curr->sibling = next->sibling;
          linkNodes(curr, next);
        } else {
          if (!prev)
            nh = next;
          else
            prev->sibling = next;
          linkNodes(next, curr);
          curr = next;
        }
      }
      next = next->sibling;
    }
    return nh;
  }

public:
  binomialHeap() : head(nullptr) {};
  void insert(int key) {
    Node *nn = new Node(key);
    nn->sibling = nullptr;
    head = unionHeap(head, nn);
  }

  void display(Node *node, int depth = 0) {
    if (!node)
      return;

    // Indentation for tree structure
    for (int i = 0; i < depth; i++)
      cout << "  ";

    cout << node->key << endl;

    // Show children recursively
    display(node->child, depth + 1);

    // Move to next sibling
    display(node->sibling, depth);
  }

  void display() {
    cout << "Binomial Heap:" << endl;
    display(head);
  }
};

int main(int argc, char *argv[]) {
  binomialHeap bheap;
  bheap.insert(1);
  bheap.insert(2);
  bheap.insert(3);
  bheap.display();

  return 0;
}
