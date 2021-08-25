#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> pre_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      pre_sum[i] = pre_sum[i - 1] + nums[i - 1];

    // sum(j,i) = pre_sum(i) - pre_sum(j-1)
    // pre_sum(j-1) == pre_sum(i) - k
    int ans = 0;
    unordered_map<int, int> map;
    for (int i = 0; i <= n; i++) {
      ans += map[pre_sum[i] - k];
      map[pre_sum[i]]++;
    }
    return ans;
  }
};
// @lc code=end
