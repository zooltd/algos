/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    // http://zxi.mytechroad.com/blog/searching/leetcode-40-combination-sum-ii/
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int st) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = st; i < candidates.size(); i++) {
            if (i > st && candidates[i] == candidates[i - 1]) continue;
            if (target < candidates[i]) break;
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

