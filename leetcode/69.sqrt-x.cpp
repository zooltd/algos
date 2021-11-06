/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
  int mySqrt(int x) {
    long long l = 0, r = x;
    long long mid;
    /* find the last n taht n^2 <= x */
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (mid * mid <= x)
        l = mid;
      else
        r = mid - 1;
    }
    return r;
  }
};
// @lc code=end
