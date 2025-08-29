#include <algorithm>
#include <bits/stdc++.h>
#include <memory_resource>
#include <unordered_map>
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
  TreeNode *construct(vector<int> &inorder, int is, int ie,
                      vector<int> &postorder, int ps, int pe,
                      unordered_map<int, int> &mp) {

    if (ie < is || pe < ps)
      return nullptr;

    TreeNode *root = new TreeNode(postorder[pe]);

    int currRoot = mp[postorder[pe]];
    int numsLeft = currRoot - is;
    root->left = construct(inorder, is, currRoot - 1, postorder, ps,
                           ps + numsLeft - 1, mp);
    root->right = construct(inorder, currRoot + 1, ie, postorder, ps + numsLeft,
                            pe - 1, mp);
    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() != postorder.size())
      return nullptr;
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i;
    }
    return construct(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1, mp);
    // Implementation to be added
  }
};

// Helper function to print the tree (preorder traversal)
void printPreorder(TreeNode *root) {
  if (!root)
    return;
  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

int main() {
  Solution sol;

  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};

  TreeNode *root = sol.buildTree(inorder, postorder);

  // Print the tree in preorder to check
  printPreorder(root);
  cout << endl;

  return 0;
}
