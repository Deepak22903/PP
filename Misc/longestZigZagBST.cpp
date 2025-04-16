#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
  int result{};
  int final = INT_MIN;
  TreeNode *head;

private:
  void dfs(TreeNode *root, bool isLeft, int result) {
    if (!root)
      return;

    final = max(final, result);

    if (isLeft) {
      dfs(root->right, false, result + 1);
      dfs(root->left, true, 1);
    } else {
      dfs(root->left, true, result + 1);
      dfs(root->right, false, 1);
    }
  }

public:
  int longestZigZag(TreeNode *root) {
    // Implementation goes here
    head = root;
    if (!root->left && !root->right) {
      return 0;
    }
    dfs(root, false, 0);
    return final;
  }
};

int main() {

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(2);
  root->right->right = new TreeNode(2);

  Solution sol;
  int result = sol.longestZigZag(root);
  cout << "Longest ZigZag Path: " << result << endl;

  return 0;
}
