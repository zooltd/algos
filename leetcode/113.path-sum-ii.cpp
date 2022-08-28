#include <vector>
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
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode* root, int targetSum) {
        if (!root) return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0)
            res.push_back(path);
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }

private:
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

class Solution2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int target, int curr) {
        if (!root->left && !root->right) {
            if (curr + root->val == target) {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        if (root->left) dfs(root->left, target, curr + root->val);
        if (root->right) dfs(root->right, target, curr + root->val);
        path.pop_back();
    }
    
private:
    vector<int> path;
    vector<vector<int>> res;
};