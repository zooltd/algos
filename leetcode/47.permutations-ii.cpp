#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    visited = new bool[nums.size()]{0};
    doPermuteUnique(nums, 0);
    return ans;
  }

  void doPermuteUnique(vector<int> &nums, int index) {
    if (index == nums.size()) {
      ans.push_back(s);
      return;
    }

    // choose which num to place
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i])
        continue;
      if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
        continue;
      visited[i] = true;
      s.push_back(nums[i]);
      doPermuteUnique(nums, index + 1);
      s.pop_back();
      visited[i] = false;
    }
  }

private:
  vector<vector<int>> ans;
  vector<int> s;
  bool *visited;
};
// @lc code=end
