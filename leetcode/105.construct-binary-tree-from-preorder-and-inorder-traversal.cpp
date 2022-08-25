#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        n = preorder.size();
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>&pre, vector<int>&in, int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        TreeNode* root = new TreeNode(pre[pl]);
        int k = pos[pre[pl]];
        root->left = build(pre, in, pl + 1, pl + k - il, il, k - 1);
        root->right = build(pre, in, pl + k - il + 1, pr, k + 1, ir);
        return root;
    }
private:
    int n;
    unordered_map<int,int> pos;
};
// @lc code=end

