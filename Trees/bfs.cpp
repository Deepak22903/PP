#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node {

  int data;
  Node *left;
  Node *right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

class BTree {
public:
  vector<int> bfs(Node *root) {
    vector<int> res;
    Node *temp = root;
    queue<Node *> q;
    q.push(temp);
    while (!q.empty()) {
      Node *curr = q.front();
      q.pop();
      res.push_back(curr->data);
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  BTree tree;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  for (auto val : tree.bfs(root)) {
    cout << val << endl;
  }

  return 0;
}
