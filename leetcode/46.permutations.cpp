#include <bits/stdc++.h>
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
    vector<bool> visited(nums.size(), false);
    dfs(nums, visited);
    return res;
  }

  void dfs(vector<int> &nums, vector<bool>& visited) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i]) continue;
      visited[i] = true;
      path.push_back(nums[i]);
      dfs(nums, visited);
      path.pop_back();
      visited[i] = false;
    }
  }

private:
  vector<vector<int>> res;
  vector<int> path;
};
// @lc code=end
