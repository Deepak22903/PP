#include <iostream>
#include <system_error>
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
public:
  int recur(TreeNode *root) {
    if (!root)
      return 0;

    int lh = recur(root->left);
    if (lh == -1)
      return -1;
    int rh = recur(root->right);
    if (rh == -1)
      return -1;

    if (abs(lh - rh) > 1)
      return -1;
    return 1 + max(lh, rh);
  }
  bool isBalanced(TreeNode *root) {

    int res = recur(root);
    if (res == -1)
      return false;
    return true;
  }
};

int main() {
  /*
      Example tree:
           3
          / \
         9  20
            /  \
           15   7
  */
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

  Solution sol;
  bool balanced = sol.isBalanced(root);
  cout << (balanced ? "Balanced" : "Not Balanced") << endl;

  // Cleanup
  delete root->left;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
