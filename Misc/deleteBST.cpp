#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  void replaceVal(TreeNode *node) {

    TreeNode *successorParent = node;
    TreeNode *successor = node->right;

    if (successor->left == nullptr) {
      node->val = successor->val;
      node->right = successor->right;
      return;
    }

    while (successor->left != nullptr) {
      successorParent = successor;
      successor = successor->left;
    }

    node->val = successor->val;

    successorParent->left = successor->right;
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key) {

    if (!root)
      return nullptr;
    TreeNode *curr = root;
    TreeNode *par = nullptr;
    TreeNode *node = nullptr;
    while (curr) {
      if (curr->val == key) {
        node = curr;
        break;
      } else {
        par = curr;
        if (key < curr->val) {
          curr = curr->left;
        } else {
          curr = curr->right;
        }
      }
    }
    if (!node) {
      return root;
    }
    if (node->left && node->right) {
      replaceVal(node);
      return root;
    } else {
      TreeNode *child = node->left ? node->left : node->right;
      if (par == nullptr) {
        return child;
      } else {
        if (par->left == node) {
          par->left = child;
        } else {
          par->right = child;
        }
        return root;
      }
    }
  }
};

void inorder(TreeNode *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main() {

  TreeNode *root = new TreeNode(5, new TreeNode(6), nullptr);

  int key = 5;

  cout << "Inorder before deletion: ";
  inorder(root);
  cout << endl;

  Solution sol;
  TreeNode *newRoot = sol.deleteNode(root, key);

  cout << "Inorder after deletion: ";
  inorder(newRoot);
  cout << endl;

  return 0;
}
