#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    vector<int> fmax(nums.size());
    vector<int> fmin(nums.size());
    fmax[0] = nums[0];
    fmin[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      fmax[i] = max({nums[i], fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]});
      fmin[i] = min({nums[i], fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]});
    }
    int ans = nums[0];
    for (int i = 0; i < nums.size(); i++)
      ans = max(ans, fmax[i]);
    return ans;
  }
};
// @lc code=end
