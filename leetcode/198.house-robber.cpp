#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    /**
     * f[i, j]: max profit
     * i: rob first i houses
     * j: whether or not break in the i-th house
     */
    vector<vector<int>> f(n + 1, vector<int>(2));
    nums.insert(nums.begin(), 0);
    f[0][0] = 0;
    f[0][1] = -1;
    for (int i = 1; i <= n; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1]);
      f[i][1] = f[i - 1][0] + nums[i];
    }
    return max(f[n][0], f[n][1]);
  }
};
// @lc code=end
