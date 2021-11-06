#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    int mid;
    vector<int> ans(2);
    /* find left bound */
    /* the first num >= target */
    while (l < r) {
      mid = (l + r) / 2;
      if (nums[mid] >= target)
        r = mid;
      else
        l = mid + 1;
    }
    ans[0] = l;

    l = -1, r = nums.size() - 1;
    /* find right bound */
    /* the last num <= target */
    while (l < r) {
      mid = (l + r + 1) / 2;
      if (nums[mid] <= target)
        l = mid;
      else
        r = mid - 1;
    }
    ans[1] = l;
    if (ans[1] < ans[0])
      ans = {-1, -1};
    return ans;
  }
};
// @lc code=end
