/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
  bool canJump(vector<int> &nums) {
    if (nums.size() <= 1)
      return true;
    int maxDis = nums[0];
    for (int i = 1; i < nums.size() - 1; i++) {
      if (i > maxDis)
        break;
      maxDis = max(maxDis, nums[i] + i);
    }
    return maxDis >= nums.size() - 1;
  }
};
// @lc code=end
