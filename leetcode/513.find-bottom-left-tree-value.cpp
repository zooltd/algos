#include <utility>
using namespace std;
/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> res = {0, root->val};
        dfs(root, res, 0);
        return res.second;
    }

    void dfs(TreeNode* root, pair<int, int>& res, int depth) {
        if (!root) return;
        if (depth > res.first) res = {depth, root->val};
        dfs(root->left, res, depth + 1);
        dfs(root->right, res, depth + 1);
    }
};
// @lc code=end

