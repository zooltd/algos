/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        const int NINF = -(1 << 32);
        queue<TreeNode*> q;
        if (root) q.push(root);
        vector<int> res;
        while (q.size()) {
            int num = NINF;
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                auto* t = q.front();
                q.pop();
                num = max(num, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(num);
        }
        return res;
    }
};
// @lc code=end

