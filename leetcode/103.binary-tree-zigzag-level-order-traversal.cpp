/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (dq.size()) {
            vector<int> level;
            int cnt = dq.size();
            while (cnt--) {
                TreeNode* t;
                if (res.size() % 2) {
                    t = dq.back();
                    dq.pop_back();
                    if (t->right) dq.push_front(t->right);
                    if (t->left) dq.push_front(t->left);
                } else {
                    t = dq.front();
                    dq.pop_front();
                    if (t->left) dq.push_back(t->left);
                    if (t->right) dq.push_back(t->right);
                }
                level.push_back(t->val);
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end

