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
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
  //   vector<int> preorder(Node *root) {
  //     find(root);
  //     return ans;
  //   }
  //   void find(Node *root) {
  //     if (!root)
  //       return;
  //     ans.push_back(root->val);
  //     for (Node *n : root->children)
  //       find(n);
  //   }
  vector<int> preorder(Node *root) {
    stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
      Node *n = s.top();
      s.pop();
      if (!n)
        break;
      ans.push_back(n->val);
      for (int i = n->children.size() - 1; i >= 0; i--)
        s.push(n->children[i]);
    }
    return ans;
  }

private:
  vector<int> ans;
};
// @lc code=end
