#include <iostream>
#include <stack>
using namespace std;
struct bst {
  int data;
  bst *left;
  bst *right;
  bst(int val) : data(val), left(nullptr), right(nullptr) {};
};

void traverse(bst *root) {
  if (!root)
    return;
  cout << root->data << endl;
  traverse(root->left);
  traverse(root->right);
}

void traverseNonRecurse(bst *root) {
  stack<bst *> s;
  s.push(root);
  while (!s.empty()) {
    bst *curr = s.top();
    s.pop();
    cout << curr->data << endl;
    if (curr->right) {
      s.push(curr->right);
    }
    if (curr->left) {
      s.push(curr->left);
    }
  }
}

int main(int argc, char *argv[]) {
  bst *obj = new bst(69);
  obj->left = new bst(59);
  obj->left->left = new bst(49);
  obj->left->right = new bst(60);
  obj->right = new bst(79);
  obj->right->left = new bst(68);
  obj->right->right = new bst(80);
  cout << "Without Recursion: \n" << endl;
  traverseNonRecurse(obj);
  cout << "With Recursion:\n" << endl;
  traverse(obj);
  return 0;
}
