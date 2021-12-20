/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    int f1 = 1;
    int f2 = 2;
    int f;
    for (int i = 3; i <= n; i++) {
      f = f1 + f2;
      f1 = f2;
      f2 = f;
    }
    return f;
  }
};
// @lc code=end
