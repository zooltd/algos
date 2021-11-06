/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    int mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (nums[mid] <= nums[r])
        r = mid;
      else
        l = mid + 1;
    }
    return nums[r];
  }
};
// @lc code=end
