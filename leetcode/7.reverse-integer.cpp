/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        if (x < -INT_MAX) return 0;
        if (x < 0) return -reverse(-x);
        unsigned long long res = 0;
        while (x) {
            int digit = x % 10;
            res = res * 10 + digit;
            x /= 10;
        }
        if (res > INT_MAX) return 0;
        return res;
    }
};
// @lc code=end

