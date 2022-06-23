/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(t1->val, t2->val);
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev && prev->val > root->val) {
            if (!t1) t1 = prev;
            t2 = root;
        }
        prev = root;
        inorder(root->right);
    }

private:
    TreeNode* t1, *t2, *prev;
};
// @lc code=end

