#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
/**
 * https://www.acwing.com/video/1379/
 */
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    dfs(nums, used);
    return res;
  }

  void dfs(vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) continue;
      if (i >= 1 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
      used[i] = true;
      path.push_back(nums[i]);
      dfs(nums, used);
      used[i] = false;
      path.pop_back();
    }
  }
private:
  vector<int> path;
  vector<vector<int>> res;
};
// @lc code=end
