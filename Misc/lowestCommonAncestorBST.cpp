#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  // Your original dfs function is fine for building the map
  // Removed unused p, q parameters from dfs signature
  void dfs(TreeNode *root) {
    if (!root)
      return;
    if (root->left) {
      map[root->left->val] = root; // map[child_val] = parent_node
      dfs(root->left);
    }
    if (root->right) {
      map[root->right->val] = root; // map[child_val] = parent_node
      dfs(root->right);
    }
  }

public:
  std::unordered_map<int, TreeNode *> map;
  // Removed unused 'sol' and 'head' members

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q)
      return nullptr; // Handle null inputs

    // Step 1: Build the parent map using your dfs
    map.clear();              // Clear map for potentially multiple calls
    map[root->val] = nullptr; // Root's parent is null
    dfs(root);

    // Step 2: Collect all ancestors of p (including p itself)
    std::unordered_set<TreeNode *> ancestors_p;
    TreeNode *curr = p;
    while (curr != nullptr) {
      ancestors_p.insert(curr);
      // Use the map to get the parent node.
      // map[curr->val] retrieves the parent TreeNode* associated with curr's
      // value.
      curr = map[curr->val];
    }

    // Step 3: Trace ancestors of q upwards. The first ancestor of q
    // found in p's ancestor set is the LCA.
    curr = q;
    while (curr != nullptr) {
      // Check if the current node (starting from q) is in p's ancestor set
      if (ancestors_p.count(curr)) {
        return curr; // This is the LCA
      }
      // Move up to the parent
      curr = map[curr->val];
    }

    return nullptr; // Should not happen if p and q are in the tree rooted at
                    // 'root'
  }
};

// Helper to build tree from level-order array with -1 as null
TreeNode *buildTree(const vector<int> &nodes,
                    unordered_map<int, TreeNode *> &valToNode) {
  if (nodes.empty())
    return nullptr;

  TreeNode *root = new TreeNode(nodes[0]);
  valToNode[nodes[0]] = root;

  queue<TreeNode *> q;
  q.push(root);
  int i = 1;

  while (i < nodes.size()) {
    TreeNode *curr = q.front();
    q.pop();

    // Left child
    if (i < nodes.size() && nodes[i] != -1) {
      curr->left = new TreeNode(nodes[i]);
      valToNode[nodes[i]] = curr->left;
      q.push(curr->left);
    }
    i++;

    // Right child
    if (i < nodes.size() && nodes[i] != -1) {
      curr->right = new TreeNode(nodes[i]);
      valToNode[nodes[i]] = curr->right;
      q.push(curr->right);
    }
    i++;
  }

  return root;
}

int main() {
  // -1 will represent null in the level-order list
  vector<int> levelOrder = {1, 2};
  unordered_map<int, TreeNode *> valToNode;

  TreeNode *root = buildTree(levelOrder, valToNode);

  TreeNode *p = valToNode[1];
  TreeNode *q = valToNode[2];

  Solution sol;
  TreeNode *lca = sol.lowestCommonAncestor(root, p, q);

  if (lca != nullptr)
    cout << "Lowest Common Ancestor: " << lca->val << endl;
  else
    cout << "Lowest Common Ancestor not found." << endl;

  return 0;
}
