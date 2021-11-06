/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    int left = 0;  // lower
    int right = 0; // upper
    for (int i = 0; i < nums.size(); i++) {
      left = max(left, nums[i]);
      right += nums[i];
    }
    while (left < right) {
      int mid = (left + right) / 2;
      if (isValid(nums, m, mid))
        right = mid;
      else
        left = mid + 1;
    }
    return right;
  }

private:
  bool isValid(vector<int> &nums, int m, int T) {
    int groupSum = 0;
    int groupCnt = 1;

    for (int i = 0; i < nums.size(); i++) {
      if (groupSum + nums[i] <= T)
        groupSum += nums[i];
      else {
        groupCnt++;
        groupSum = nums[i];
      }
    }
    return groupCnt <= m;
  }
};
// @lc code=end
