/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0;
        inorder(root, low, high);
        return ans;
    }

    void inorder(TreeNode* root, int low, int high) {
        if (!root) return;
        inorder(root->left, low, high);
        int value = root->val;
        if (low <= value && value <= high)
            ans += value;
        inorder(root->right, low, high);
    }
private:
    int ans;
};
// @lc code=end

