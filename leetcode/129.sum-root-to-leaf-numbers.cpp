/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if (root) dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int val, int& ans) {
        val = val * 10 + root->val;
        if (!root->left && !root->right) ans += val;
        if (root->left) dfs(root->left, val, ans);
        if (root->right) dfs(root->right, val, ans);
    }
};
// @lc code=end

