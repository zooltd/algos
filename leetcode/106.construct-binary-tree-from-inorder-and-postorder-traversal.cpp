/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return nullptr;
        int n = inorder.size() - 1;
        for (int i = 0; i <= n; i++) mp[inorder[i]] = i;
        return build(inorder, postorder, 0, n, 0, n);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if (pl > pr) return nullptr;
        TreeNode* root = new TreeNode(postorder[pr]);
        int k = mp[root->val];
        root->left = build(inorder, postorder, il, k - 1, pl, k - 1 - il + pl);
        root->right = build(inorder, postorder, k + 1, ir, k - il + pl, pr - 1);
        return root;
    }

private:
    unordered_map<int, int> mp;
};
// @lc code=end

