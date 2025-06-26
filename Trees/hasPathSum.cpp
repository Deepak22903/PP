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
public:
  bool recur(TreeNode *root, int targetSum, int currSum) {
    if (!root) {
      return false;
    }
    currSum += root->val;
    if (!root->left && !root->right)
      return currSum == targetSum;

    if (recur(root->left, targetSum, currSum))
      return true;
    if (recur(root->right, targetSum, currSum))
      return true;
    return false;
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    return recur(root, targetSum, 0);
  }
};

int main() {
  /*
      Tree:
             5
            / \
           4   8
          /   / \
         11  13  4
        /  \
       7    2
  */
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2, nullptr, nullptr);
  root->right = new TreeNode(3, nullptr, nullptr);

  int targetSum = 5;

  Solution sol;
  bool result = sol.hasPathSum(root, targetSum);
  cout << (result ? "Path exists" : "No path") << endl;

  return 0;
}
