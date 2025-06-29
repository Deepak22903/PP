#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int d) {
    data = d;
    left = nullptr;
    right = nullptr;
  }
};

int recur(Node *root, int &maxSum) {
  if (!root)
    return 0;
  int leftSum = recur(root->left, maxSum);
  int rightSum = recur(root->right, maxSum);
  maxSum = max(maxSum, leftSum + rightSum + root->data);

  return max(leftSum, rightSum) + root->data;
}
int maxPathSum(Node *root) {
  int maxSum = INT_MIN;
  int res = recur(root, maxSum);
  return maxSum;
}
int main(int argc, char *argv[]) {
  Node *root = new Node(-10);
  root->left = new Node(9);
  root->right = new Node(20);
  root->right->left = new Node(15);
  root->right->right = new Node(7);
  cout << "Max Sum = " << maxPathSum(root) << endl;

  return 0;
}
