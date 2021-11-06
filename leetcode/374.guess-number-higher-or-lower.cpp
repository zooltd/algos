/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {
    int l = 1, r = n;
    int mid;
    while (l < r) {
      mid = l + (r - l) / 2;
      if (guess(mid) <= 0)
        r = mid;
      else
        l = mid + 1;
    }
    return r;
  }
};
// @lc code=end
