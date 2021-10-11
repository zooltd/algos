#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
public:
  Trie() : children(26), isEnd(false) {}

  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (children[i] != nullptr)
        delete children[i];
    }
  }

  void insert(string word) {
    Trie *curr = this;
    int idx;
    for (const char ch : word) {
      idx = ch - 'a';
      if (curr->children[idx] == nullptr)
        curr->children[idx] = new Trie();
      curr = curr->children[idx];
    }
    curr->isEnd = true;
  }

  bool search(string word) {
    Trie *node = this->searchPrefix(word);
    return node != nullptr && node->isEnd;
  }

  bool startsWith(string prefix) {
    return this->searchPrefix(prefix) != nullptr;
  }

private:
  vector<Trie *> children;
  bool isEnd;

  Trie *searchPrefix(string prefix) {
    Trie *curr = this;
    int idx;
    for (const char ch : prefix) {
      idx = ch - 'a';
      if (curr->children[idx] == nullptr) {
        return nullptr;
      }
      curr = curr->children[idx];
    }
    return curr;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
