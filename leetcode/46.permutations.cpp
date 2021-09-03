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
    visited = new bool[nums.size()]{0};
    doPermute(nums, 0);
    delete[] visited;
    return ans;
  }

  void doPermute(vector<int> &nums, int index) {
    if (index == nums.size()) {
      ans.push_back(s);
      return;
    }

    // choose which num to place
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i])
        continue;
      visited[i] = true;
      s.push_back(nums[i]);
      doPermute(nums, index + 1);
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
