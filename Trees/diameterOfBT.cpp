#include <climits>
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
  int height(TreeNode *root, int &maxDia) {
    if (!root)
      return 0;
    int lh = height(root->left, maxDia);
    int rh = height(root->right, maxDia);
    int currDia = lh + rh;
    maxDia = max(maxDia, currDia);
    return 1 + max(lh, rh);
  }
  int diameterOfBinaryTree(TreeNode *root) {
    // Implementation to be added
    int maxd = INT_MIN;
    height(root, maxd);
    return maxd;
  }
};

int main() {
  /*
      Example tree:
           1
          / \
         2   3
        / \
       4   5

      Expected diameter: 3 (path: 4 -> 2 -> 5 or 4 -> 2 -> 1 -> 3)
  */
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->left = new TreeNode(4);
  root->right->right->left->right = new TreeNode(5);

  Solution sol;
  int diameter = sol.diameterOfBinaryTree(root);
  cout << "Diameter: " << diameter << endl;

  return 0;
}
