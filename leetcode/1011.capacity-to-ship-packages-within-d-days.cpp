#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int left = 0, right = 0;
    for (int i = 0; i < weights.size(); i++) {
      left = max(left, weights[i]);
      right += weights[i];
    }
    int mid;
    while (left < right) {
      mid = (left + right) / 2;
      if (isValid(weights, days, mid))
        right = mid;
      else
        left = mid + 1;
    }
    return right;
  }

private:
  bool isValid(vector<int> &weights, int days, int T) {
    int total_days = 1;
    int daily_weight = 0;
    for (int weight : weights) {
      if (daily_weight + weight <= T)
        daily_weight += weight;
      else {
        daily_weight = weight;
        total_days++;
      }
    }
    return days >= total_days;
  }
};
// @lc code=end
