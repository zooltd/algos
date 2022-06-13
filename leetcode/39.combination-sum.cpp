/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int target, int i) {
        if (target == 0) {
            res.push_back(path);
            return;
        } else if (target < 0) return;

        if (i >= candidates.size()) return;

        path.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i);

        path.pop_back();
        dfs(candidates, target, i + 1);
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

