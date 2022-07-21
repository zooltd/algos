/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int target, int st) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = st; i < candidates.size(); i++) {
            if (target < candidates[i]) break; 
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

