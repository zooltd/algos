#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> value2index;
    for (int i = 0; i < nums.size(); i++) {
      auto itr = value2index.find(target - nums[i]);
      if (itr != value2index.end()) {
        return {itr->second, i};
      }
      value2index[nums[i]] = i;
    }
    return {};
  }
};
// @lc code=end
