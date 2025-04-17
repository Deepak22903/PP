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
  void dfs(TreeNode *root, int val) {
    if (!root)
      return;
    if (root->val == val) {
      res = root;
      return;
    }
    if (root->left)
      dfs(root->left, val);
    if (root->right)
      dfs(root->right, val);
  }

public:
  TreeNode *res = nullptr;
  TreeNode *searchBST(TreeNode *root, int val) {
    // Implementation goes here
    dfs(root, val);
    return res;
  }
};

int main() {
  // Example usage
  TreeNode *root = new TreeNode(
      4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));
  int searchVal = 5;

  Solution sol;
  TreeNode *result = sol.searchBST(root, searchVal);

  if (result)
    cout << "Found node with value: " << result->val << endl;
  else
    cout << "Value not found in BST." << endl;

  // Clean up dynamically allocated memory if needed
  return 0;
}
