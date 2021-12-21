#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size(), maxLen = 0, ans = 0;
    vector<int> dp(n, 1), cnt(n, 1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++)
        if (nums[i] > nums[j]) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            cnt[i] = cnt[j];
          } else if (dp[j] + 1 == dp[i]) {
            cnt[i] += cnt[j];
          }
        }
    return cnt[n - 1];
  }
};
// @lc code=end
