#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(righ
};
/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  //   vector<int> inorderTraversal(TreeNode *root) {
  //     find(root);
  //     return ans;
  //   }
  //   void find(TreeNode *root) {
  //     if (!root)
  //       return;
  //     find(root->left);
  //     ans.push_back(root->val);
  //     find(root->right);
  //   }
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    s.push(nullptr);
    while (!s.empty()) {
      while (root) {
        s.push(root);
        root = root->left;
      }
      root = s.top();
      s.pop();
      if (!root)
        break;
      ans.push_back(root->val);
      root = root->right;
    }
    return ans;
  }

private:
  vector<int> ans;
};
// @lc code=end
