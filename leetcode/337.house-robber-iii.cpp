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
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (mem.find(root) != mem.end()) return mem[root];
        // steal parent node
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
        // not steal parent node
        int val2 = rob(root->left) + rob(root->right);

        int val = max(val1, val2);
        mem[root] = val;
        return val;
    }
private:
    unordered_map<TreeNode*, int> mem;
};
// @lc code=end

// brute force
class Solution2 {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        // steal parent node
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
        // not steal parent node
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        return max(val1, val2);
    }
};

// dp on trees
class Solution3 {
public:
    int rob(TreeNode* root) {
        vector<int> result = postorder(root);
        return max(result[0], result[1]);
    }

    /**
    * @return vector<int>: {not steal node `cur`, steal node `cur`}
    */
    vector<int> postorder(TreeNode* cur) {
        if (!cur) return {0, 0};
        vector<int> left = postorder(cur->left);
        vector<int> right = postorder(cur->right);
        // steal
        int val1 = cur->val + left[0] + right[0];
        // not steal
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};