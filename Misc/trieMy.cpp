
#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
  struct node {
    node *arr[26];
    bool isEnd;
    node() {
      for (int i = 0; i < 26; i++) {
        arr[i] = nullptr;
      }
      isEnd = false;
    }
  };
  node *root = nullptr;
  Trie() { root = new node; }

  void insert(string word) {
    node *curr = root;
    for (auto c : word) {
      int pos = c - 97;
      if (!curr->arr[pos])
        curr->arr[pos] = new node;
      curr = curr->arr[pos];
    }
    curr->isEnd = true;
  }

  bool search(string word) {
    node *curr = root;
    for (auto c : word) {
      int pos = c - 97;
      if (!curr->arr[pos]) {
        return false;
      }
      curr = curr->arr[pos];
    }

    return curr->isEnd;
  }

  bool startsWith(string prefix) {
    node *curr = root;
    for (auto c : prefix) {
      int pos = c - 97;
      if (!curr->arr[pos]) {
        return false;
      }
      curr = curr->arr[pos];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie *obj = new Trie();
  string word = "apple";
  string prefix = "app";
  string searchWord = "applz";

  obj->insert(word);
  bool param_2 = obj->search(searchWord);
  bool param_3 = obj->startsWith(prefix);

  // Example outputs (placeholders)
  cout << "Search result: " << param_2 << endl;
  cout << "StartsWith result: " << param_3 << endl;

  delete obj;
  return 0;
}
