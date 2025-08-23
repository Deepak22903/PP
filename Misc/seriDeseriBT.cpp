/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root)
      return "";
    string out = "";
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty()) {
      TreeNode *curr = qu.front();
      if (curr) {
        if (curr->left)
          qu.push(curr->left);
        else {
          TreeNode *tmp = nullptr;
          qu.push(tmp);
        }
        if (curr->right)
          qu.push(curr->right);
        else {
          TreeNode *tmp = nullptr;
          qu.push(tmp);
        }
      }
      if (curr)
        out += to_string(curr->val) + " ";
      else
        out += "null ";

      qu.pop();
    }
    out.pop_back();
    cout << out << endl;
    return out;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty())
      return nullptr;
    stringstream ss(data);
    string token;
    vector<string> arr;
    while (ss >> token) {
      arr.push_back(token);
    }
    queue<TreeNode *> qu;
    TreeNode *root = new TreeNode(stoi(arr[0]));
    qu.push(root);
    int i = 0;
    int n = arr.size();
    while (!qu.empty()) {
      TreeNode *curr = qu.front();
      if (2 * i + 1 < n && arr[2 * i + 1] != "null") {
        curr->left = new TreeNode(stoi(arr[2 * i + 1]));
        qu.push(curr->left);
      }
      if (2 * i + 2 < n && arr[2 * i + 2] != "null") {
        curr->right = new TreeNode(stoi(arr[2 * i + 2]));
        qu.push(curr->right);
      }
      i++;
      qu.pop();
    }

    return root;
  }
};

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (!p && !q)
    return true;
  if (!p || !q)
    return false;
  if (p->val != q->val)
    return false;
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
  Codec ser, deser;

  auto test = [&](TreeNode *root, const string &caseName) {
    string data = ser.serialize(root);
    TreeNode *res = deser.deserialize(data);
    cout << caseName << ": " << data << " --> ";
    cout << (isSameTree(root, res) ? "PASS" : "FAIL") << endl;
  };

  // --- Edge Case 1: Empty tree ---
  test(nullptr, "Case 1 (empty tree)");

  // --- Edge Case 2: Single node ---
  TreeNode *root2 = new TreeNode(1);
  test(root2, "Case 2 (single node)");

  // --- Edge Case 3: Left-skewed tree ---
  TreeNode *root3 = new TreeNode(1);
  root3->left = new TreeNode(2);
  root3->left->left = new TreeNode(3);
  test(root3, "Case 3 (left skewed)");

  // --- Edge Case 4: Right-skewed tree ---
  TreeNode *root4 = new TreeNode(1);
  root4->right = new TreeNode(2);
  root4->right->right = new TreeNode(3);
  test(root4, "Case 4 (right skewed)");

  // --- Edge Case 5: Complete binary tree ---
  TreeNode *root5 = new TreeNode(1);
  root5->left = new TreeNode(2);
  root5->right = new TreeNode(3);
  root5->left->left = new TreeNode(4);
  root5->left->right = new TreeNode(5);
  root5->right->left = new TreeNode(6);
  root5->right->right = new TreeNode(7);
  test(root5, "Case 5 (complete tree)");

  // --- Edge Case 6: Tree with mixed nulls ---
  TreeNode *root6 = new TreeNode(1);
  root6->left = new TreeNode(2);
  root6->right = new TreeNode(3);
  root6->left->right = new TreeNode(4);
  root6->right->right = new TreeNode(5);
  test(root6, "Case 6 (mixed nulls)");

  return 0;
}
