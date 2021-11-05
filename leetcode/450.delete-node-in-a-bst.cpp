#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return nullptr;
    if (key == root->val) {
      if (root->left == nullptr)
        return root->right;
      if (root->right == nullptr)
        return root->left;
      TreeNode *next = root->right;
      while (next->left != nullptr)
        next = next->left;
      root->right = deleteNode(root->right, next->val);
      root->val = next->val;
      return root;
    }
    if (key < root->val)
      root->left = deleteNode(root->left, key);
    else
      root->right = deleteNode(root->right, key);
    return root;
  }
};
// @lc code=end
