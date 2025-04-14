
#include <iostream>
#include <stack>
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
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    TreeNode *temp1 = root1;
    TreeNode *temp2 = root2;
    vector<int> tree1;
    vector<int> tree2;
    stack<TreeNode *> ts;
    ts.push(root1);
    while (!ts.empty()) {
      TreeNode *curr = ts.top();
      ts.pop();
      if (curr->right)
        ts.push(curr->right);
      if (curr->left)
        ts.push(curr->left);
      if (!curr->left && !curr->right)
        tree1.push_back(curr->val);
    }

    ts.push(root2);
    while (!ts.empty()) {
      TreeNode *curr = ts.top();
      ts.pop();
      if (curr->right)
        ts.push(curr->right);
      if (curr->left)
        ts.push(curr->left);
      if (!curr->left && !curr->right)
        tree2.push_back(curr->val);
    }
    return tree1 == tree2 ? true : false;
  }
};

int main() {
  /*
      Tree 1:
              3
             / \
            5   1
           / \  / \
          6  2 9  8
            / \
           7   4

      Tree 2:
              3
             / \
            5   1
           / \  / \
          6  7 4  2
                    / \
                   9   8

      Leaf sequences:
      Tree 1: [6, 7, 4, 9, 8]
      Tree 2: [6, 7, 4, 9, 8]
  */

  // Tree 1
  TreeNode *root1 = new TreeNode(3);
  // Tree 2
  TreeNode *root2 = new TreeNode(3);
  Solution sol;
  bool result = sol.leafSimilar(root1, root2);

  cout << (result ? "True" : "False") << endl;

  return 0;
}
