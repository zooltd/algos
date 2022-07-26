/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res = nullptr;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int state = dfs(root->left, p, q);
        if (root == p) state |= 0x1;
        else if (root == q) state |= 0x10;
        state |= dfs(root->right, p, q);
        if (state == 0x11 && !res) res = root;
        return state;
    }

    /**
    * @brief https://www.acwing.com/activity/content/code/content/1404142/
    */
    TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
        helper(root);
        // tracing back from p to root
        while (p->val != root->val) {
            path.insert(p->val);
            p = father[p->val];
        }
        path.insert(root->val);
        
        while (path.find(q->val) == path.end())
            q = father[q->val];
        return q;
    }

private:
    void helper(TreeNode *root) {
        if (!root) return;
        if (root->left) {
            father[root->left->val] = root;
            helper(root->left);
        }
        if (root->right) {
            father[root->right->val] = root;
            helper(root->right);
        }
    }
    unordered_map<int, TreeNode *> father;
    // path to p from root
    unordered_set<int> path;
};
// @lc code=end
