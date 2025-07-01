#include <climits>
#include <iostream>
#include <queue>
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
  int maxLevelSum(TreeNode *root) {
    pair<int, int> maxSum = {0, INT_MIN};
    queue<TreeNode *> q;
    if (!root)
      return 0;
    q.push(root);
    int lev = 0;
    while (!q.empty()) {
      int size = q.size();
      int currSum = 0;
      lev++;
      for (int i = 0; i < size; i++) {
        currSum += q.front()->val;
        if (q.front()->left)
          q.push(q.front()->left);
        if (q.front()->right)
          q.push(q.front()->right);
        q.pop();
      }
      if (currSum > maxSum.second)
        maxSum = {lev, max(maxSum.second, currSum)};
    }
    return maxSum.first;
    // Implementation goes here
  }
};

int main() {
  // Constructing the following tree:
  //         5
  //        / \
    //       2   12
  //      / \    \
    //     1   3    20

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(50);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(20);

  Solution sol;
  int result = sol.maxLevelSum(root);
  cout << "Max level sum is at level: " << result << endl;

  return 0;
}
