/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        res = true;
        height(root);
        return res;
    }

private:
    int height(TreeNode* root) {
        if (!root) return 0;
        int lh = height(root->left), rh = height(root->right);
        if (abs(lh - rh) > 1) res = false;
        return 1 + max(lh, rh);
    }
private:
    bool res;
};
// @lc code=end

