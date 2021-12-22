#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1)
      return false;
    sum /= 2;

    vector<bool> f(sum + 1, false);
    f[0] = true;

    for (int i = 1; i <= n; i++)
      for (int j = sum; j >= nums[i]; j--)
        f[j] = f[j] | f[j - nums[i]];

    return f[sum];
  }
};
// @lc code=end
