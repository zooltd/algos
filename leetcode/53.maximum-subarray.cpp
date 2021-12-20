#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    vector<int> f(nums.size());
    f[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
      f[i] = max(f[i - 1] + nums[i], nums[i]);
    int ans = nums[0];
    for (int i = 0; i < nums.size(); i++)
      ans = max(ans, f[i]);
    return ans;
  }
};
// @lc code=end
