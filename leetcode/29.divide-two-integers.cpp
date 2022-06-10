/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief https://leetcode.com/problems/divide-two-integers/discuss/1516367/Complete-Thinking-Process-or-Intuitive-Explanation-or-All-rules-followed-or-C%2B%2B-code
     */
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        bool isPositive = (dividend ^ divisor) >= 0;
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){
            short q = 0;
            while(a > (b << (q + 1))) q++;
            ans += (1 << q);
            a = a - (b << q);
        }
        if (ans == (1<<31) && isPositive) return INT_MAX;
        return isPositive ? ans : -ans;
    }
};
// @lc code=end

