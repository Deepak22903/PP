#include <iostream>
#include <queue>
#include <utility>
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
public:
  vector<int> rightSideView(TreeNode *root) {
    if (!root)
      return {};
    vector<int> res;
    // Implementation left blank
    queue<pair<TreeNode *, int>> tq;
    TreeNode *lastnode = nullptr;
    int currDepth = 0;
    tq.push({root, 1});
    while (!tq.empty()) {
      TreeNode *curr;
      int depth;
      curr = tq.front().first;
      depth = tq.front().second;
      tq.pop();
      if (depth != currDepth) {
        if (lastnode)
          res.push_back(lastnode->val);
        currDepth = depth;
      }
      lastnode = curr;
      if (curr->left)
        tq.push({curr->left, depth + 1});
      if (curr->right)
        tq.push({curr->right, depth + 1});
    }
    if (lastnode)
      res.push_back(lastnode->val);
    return res;
  }
};

int main() {
  // Example usage
  TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  // root->left->left->right = new TreeNode(6);

  Solution sol;
  vector<int> result = sol.rightSideView(root);

  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;

  // Free allocated memory
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
