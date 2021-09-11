#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    if (!root)
      return {};
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      Node *node = q.front().first;
      int depth = q.front().second;
      q.pop();
      if (ans.size() <= depth)
        ans.push_back({});
      ans[depth].push_back(node->val);
      for (Node *child : node->children)
        q.push({child, depth + 1});
    }
    return ans;
  }

private:
  vector<vector<int>> ans;
};
// @lc code=end
