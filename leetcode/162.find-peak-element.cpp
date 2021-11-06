/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int lmid = (l + r) / 2;
      int rmid = lmid + 1;
      if (nums[lmid] < nums[rmid])
        l = lmid + 1;
      else
        r = rmid - 1;
    }
    return r;
  }
};
// @lc code=end
