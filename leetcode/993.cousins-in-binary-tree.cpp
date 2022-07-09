/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    bool isCousins(TreeNode* root, int x, int y) {
        x_dep = x_fa = y_dep = y_fa = -1;
        dfs(root, x, y, 0, -1);
        return x_dep == y_dep && x_fa != y_fa;
    }

    void dfs(TreeNode* root, int x, int y, int dep, int fa) {
        if (!root) return;
        if (root->val == x) {
            x_dep = dep;
            x_fa = fa;
            return;
        }
        if (root->val == y) {
            y_dep = dep;
            y_fa = fa;
            return;
        }
        dfs(root->left, x, y, dep + 1, root->val);
        dfs(root->right, x, y, dep + 1, root->val);
    }

private:
    int x_dep, x_fa;
    int y_dep, y_fa;
};
// @lc code=end

