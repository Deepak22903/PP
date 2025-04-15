
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
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
  int count{};
  int pathSum(TreeNode *root, int targetSum) {
    // Implementation to be added
    vector<int> path;
    pathSumHelper(root, targetSum, path);
    return count;
  }
  void pathSumHelper(TreeNode *root, int targetSum, vector<int> path) {
    if (!root)
      return;
    path.push_back(root->val);
    int sum{};
    for (int i = path.size() - 1; i >= 0; i--) {
      sum += path[i];
      if (sum == targetSum) {
        count++;
      }
    }
    pathSumHelper(root->left, targetSum, path);
    pathSumHelper(root->right, targetSum, path);
    path.pop_back();
  }
};

int main() {
  // Construct the tree: [10,5,-3,3,2,null,11,3,-2,null,1]
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(-3);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(2);
  root->right->right = new TreeNode(11);

  root->left->left->left = new TreeNode(3);
  root->left->left->right = new TreeNode(-2);
  root->left->right->right = new TreeNode(1);

  int targetSum = 8;
  Solution sol;
  int result = sol.pathSum(root, targetSum);

  cout << "Number of paths with sum " << targetSum << ": " << result << endl;

  // Cleanup (manually delete all nodes to avoid memory leaks)
  delete root->left->left->left;
  delete root->left->left->right;
  delete root->left->right->right;
  delete root->left->left;
  delete root->left->right;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
