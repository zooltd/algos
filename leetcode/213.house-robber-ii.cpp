#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    nums.insert(nums.begin(), 0);
    int ans;
    // a cycle exists in a searching tree, cut the edge in the cycle
    // then handle 2 cases

    vector<vector<int>> f(n + 1, vector<int>(2, 0));
    f[0][1] = -1; // invalid

    // not rob the first house, can rob the n-th house
    f[1][0] = 0;
    f[1][1] = -1; // invalid
    for (int i = 2; i <= n; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1]);
      f[i][1] = f[i - 1][0] + nums[i];
    }
    ans = max(f[n][0], f[n][1]);

    // can rob the n-th house, not rob the n-th house
    f[1][0] = 0;
    f[1][1] = nums[1];
    for (int i = 2; i <= n; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1]);
      f[i][1] = f[i - 1][0] + nums[i];
    }
    ans = max(ans, f[n][0]);

    return ans;
  }
};
// @lc code=end
