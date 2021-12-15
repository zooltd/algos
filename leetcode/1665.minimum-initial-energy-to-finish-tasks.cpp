#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1665 lang=cpp
 *
 * [1665] Minimum Initial Energy to Finish Tasks
 */

// @lc code=start
class Solution {
public:
  int minimumEffort(vector<vector<int>> &tasks) {
    sort(tasks.begin(), tasks.end(), [&](const auto &a, const auto &b) {
      return a[1] - a[0] < b[1] - b[0];
    });
    int ans = 0;
    for (const auto &task : tasks)
      ans = max(ans + task[0], task[1]);
    return ans;
  }
};
// @lc code=end
