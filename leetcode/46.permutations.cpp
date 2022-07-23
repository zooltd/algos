#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
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
