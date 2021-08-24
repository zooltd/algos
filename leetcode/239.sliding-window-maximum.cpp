#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < nums.size(); i++) {
      while (!q.empty() && q.front() <= i - k)
        q.pop_front();
      while (!q.empty() && nums[q.back()] <= nums[i])
        q.pop_back();
      q.push_back(i);
      if (i >= k - 1)
        ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};
// @lc code=end
