#include <iostream>
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
  void maxd(TreeNode *root, int depth, int &maxDepth) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      maxDepth = max(maxDepth, depth);
    }
    maxd(root->left, depth + 1, maxDepth);
    maxd(root->right, depth + 1, maxDepth);
  }

public:
  int maxDepth(TreeNode *root) {
    // Implementation to be added
    if (!root)
      return 0;
    int res = 0;
    maxd(root, 1, res);

    return res;
  }
};

int main() {
  // Create sample tree: [3,9,20,null,null,15,7]
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

  Solution sol;
  int depth = sol.maxDepth(root);
  cout << "Max depth: " << depth << endl;

  // Cleanup
  delete root->left;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
