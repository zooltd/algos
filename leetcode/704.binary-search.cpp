#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    if (nums.empty())
      return -1;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    if (nums[left] == target)
      return left;
    return -1;
  }
};
// @lc code=end
