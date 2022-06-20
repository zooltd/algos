/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }
        int k = u + 1;
        while(k < nums.size() && nums[k] == nums[u]) k++;
        dfs(nums, k);
        for (int i = u; i < k; i++) {
            path.push_back(nums[i]);
            dfs(nums, k);
        }
        path.erase(path.end() - (k - u), path.end());
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

