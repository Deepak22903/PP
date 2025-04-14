
#include <algorithm>
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
  int goodNodes(TreeNode *root) {
    // Implementation goes here
    vector<int> arr;
    stack<pair<TreeNode *, vector<int>>> ts;

    int count{};
    ts.push({root, {root->val}});
    while (!ts.empty()) {
      auto [curr, arr] = ts.top();
      ts.pop();
      if (curr->val >= *max_element(arr.begin(), arr.end())) {
        count++;
      }
      if (curr->right) {
        arr.push_back(curr->val);
        ts.push({curr->right, arr});
      }
      if (curr->left) {
        arr.push_back(curr->val);
        ts.push({curr->left, arr});
      }
    }

    return count;
  }
};

int main() {
  /*
      Tree:
              3
             / \
            1   4
           /   / \
          3   1   5

      Input: root = [3,1,4,3,null,1,5]
      Expected good nodes: 3 (root), 3 (left->left), 4, 5
  */

  TreeNode *root = new TreeNode(3);
  Solution sol;
  int result = sol.goodNodes(root);

  cout << "Good nodes count: " << result << endl;

  return 0;
}
