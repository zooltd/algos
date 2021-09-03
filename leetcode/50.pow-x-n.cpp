#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
  double myPow(double x, long n) {
    if (n < 0)
      return 1 / myPow(x, -n);
    if (n == 0)
      return 1;
    double half = myPow(x, n / 2);
    return n % 2 != 0 ? half * half * x : half * half;
  }
};
// @lc code=end
