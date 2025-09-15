#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node *cloneUtil(Node *node, unordered_map<Node *, Node *> &mp) {
    Node *temp = new Node(node->val);
    mp[node] = temp;
    for (auto neighbor : node->neighbors) {
      if (mp.find(neighbor) == mp.end()) {
        temp->neighbors.push_back(cloneUtil(neighbor, mp));
      } else {
        temp->neighbors.push_back(mp[neighbor]);
      }
    }
    return temp;
  }
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;
    unordered_map<Node *, Node *> mp;
    return cloneUtil(node, mp);
  }
};

// Utility: Print graph (BFS)
void printGraph(Node *node) {
  if (!node)
    return;
  unordered_set<Node *> visited;
  queue<Node *> q;
  q.push(node);
  visited.insert(node);

  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();
    cout << "Node " << curr->val << " connected to: ";
    for (auto neigh : curr->neighbors) {
      cout << neigh->val << " ";
      if (!visited.count(neigh)) {
        visited.insert(neigh);
        q.push(neigh);
      }
    }
    cout << "\n";
  }
}

int main() {
  // Build a simple test graph: 1--2, 1--4, 2--3, 3--4
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);

  node1->neighbors = {node2, node4};
  node2->neighbors = {node1, node3};
  node3->neighbors = {node2, node4};
  node4->neighbors = {node1, node3};

  cout << "Original Graph:\n";
  printGraph(node1);

  Solution sol;
  Node *cloned = sol.cloneGraph(node1);

  cout << "\nCloned Graph:\n";
  printGraph(cloned);

  return 0;
}
