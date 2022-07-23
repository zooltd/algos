#include <vector>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int st) {
        if (path.size() >= 2) res.push_back(path);
        unordered_set<int> used;
        for (int i = st; i < nums.size(); i++) {
            if (path.size() && path.back() > nums[i]) continue;
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

private:
    vector<int> path;
    vector<vector<int>> res;
};

class Solution2 {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int st) {
        if (path.size() >= 2) res.push_back(path);
        bool used[201] = {false};
        for (int i = st; i < nums.size(); i++) {
            if (path.size() && path.back() > nums[i]) continue;
            if (used[nums[i]]) continue;
            used[nums[i]] = true;
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

private:
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

