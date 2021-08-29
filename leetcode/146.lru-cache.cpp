#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
  LRUCache(int capacity) : cap(capacity) {
    head.next = &tail;
    tail.prev = &head;
  }

  int get(int key) {
    if (cache.find(key) == cache.end())
      return -1;
    Node *node = cache[key];
    removeFromList(node);
    insertToList(node);
    return node->value;
  }

  void put(int key, int value) {
    if (cache.find(key) == cache.end()) {
      Node *node = new Node(key, value);
      insertToList(node);
      cache[key] = node;
    } else {
      Node *node = cache[key];
      node->value = value;
      removeFromList(node);
      insertToList(node);
    }
    if (cache.size() > cap) {
      Node *node = tail.prev;
      removeFromList(node);
      cache.erase(node->key);
      delete node;
    }
  }

private:
  struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int key, int value)
        : key(key), value(value), prev(nullptr), next(nullptr) {}
  };

  void removeFromList(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void insertToList(Node *node) {
    head.next->prev = node;
    node->next = head.next;
    head.next = node;
    node->prev = &head;
  }

  int cap;
  Node head;
  Node tail;
  unordered_map<int, Node *> cache;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
