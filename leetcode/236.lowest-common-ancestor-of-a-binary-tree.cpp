#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return lcs;
    }

    int dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return 0b00;
        int state = 0b00;
        if (root == p) state |= 0b1;
        else if (root == q) state |= 0b10;
        state |= dfs(root->left, p, q);
        state |= dfs(root->right, p, q);
        if (state == 0b11 && !lcs) lcs = root;
        return state;
    }

private:
    TreeNode *lcs = nullptr;
};

// @lc code=end

// https://www.acwing.com/activity/content/code/content/1404142/
class Solution2 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, nullptr);

        unordered_set<TreeNode *> parents_p;
        for (auto *node = p; node; node = parents[node])
            parents_p.insert(node);
        for (auto *node = q; node; node = parents[node])
            if (parents_p.count(node)) return node;
        return nullptr;
    }

    void dfs(TreeNode *root, TreeNode *parent) {
        if (!root) return;
        parents[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }

private:
    unordered_map<TreeNode *, TreeNode *> parents;
};

class Solution3 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return root;

        // If p or q if found, return the root.
        if (root == p || root == q) return root;

        // Save the root found at left and right recursively
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // If both the nodes are found, return parent of that node. That will be root.
        if (left && right) return root;
        // If left is found, and right is not found.
        // It is given that both the p and q will exist for sure.
        // If left present then right will be a decendent of left, or vice versa.
        return left ? left : right;
    }
};