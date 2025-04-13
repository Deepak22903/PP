
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
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
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    stack<pair<TreeNode *, int>> ts;
    ts.push({root, 1});
    int maxDepth = INT_MIN;
    while (!ts.empty()) {
      auto [node, depth] = ts.top();
      ts.pop();
      maxDepth = max(maxDepth, depth);
      if (node->left)
        ts.push({node->left, depth + 1});
      if (node->right)
        ts.push({node->right, depth + 1});
    }
    return maxDepth;
  }
  // int maxDepth(TreeNode *root) {
  //   if (!root)
  //     return 0;
  //   stack<TreeNode *> ts;
  //   int depth{1};
  //   int maxDepth = INT_MIN;
  //   ts.push(root);
  //   while (!ts.empty()) {
  //     TreeNode *curr = ts.top();
  //     ts.pop();
  //     if (ts.empty()) {
  //       if (depth > maxDepth) {
  //         maxDepth = depth;
  //         depth = 0;
  //       }
  //     }
  //     if (curr->right) {
  //       ts.push(curr->right);
  //     }
  //     if (curr->left) {
  //       ts.push(curr->left);
  //     }
  //     depth++;
  //   }
  //   if (depth > maxDepth) {
  //     maxDepth = depth;
  //   }
  //   return maxDepth;
  // }
};

int main() {
  // Building the tree [1,2,3,4,5]
  TreeNode *node4 = new TreeNode(4);
  TreeNode *node5 = new TreeNode(5);
  TreeNode *node2 = new TreeNode(2, node4, node5);
  TreeNode *node3 = new TreeNode(3);
  TreeNode *root = new TreeNode(1, node2, node3);

  Solution sol;
  int result = sol.maxDepth(root);
  cout << "Max Depth: " << result << endl;

  // Clean up memory
  delete node4;
  delete node5;
  delete node2;
  delete node3;
  delete root;

  return 0;
}
