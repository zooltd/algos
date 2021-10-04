/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    recordFather(root);
    redNodes.insert(root->val);
    while (p->val != root->val) {
      redNodes.insert(p->val);
      p = father[p->val];
    }
    while (redNodes.find(q->val) == redNodes.end()) {
      q = father[q->val];
    }
    return q;
  }

private:
  void recordFather(TreeNode *root) {
    if (!root)
      return;
    if (root->left) {
      father[root->left->val] = root;
      recordFather(root->left);
    }
    if (root->right) {
      father[root->right->val] = root;
      recordFather(root->right);
    }
  }
  unordered_map<int, TreeNode *> father;
  set<int> redNodes;
};
// @lc code=end
