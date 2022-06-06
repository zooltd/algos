/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int n = s.size();
        while (i < n && s[i] == ' ') i++;
        if (s[i] == '+' || s[i] == '-') {
            sign = 1 - 2 * (s[i] == '-');
            i++;
        }
        unsigned long long base = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            base = 10 * base + (s[i++] - '0');
            if (base > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        return (int) (sign * base);
    }
};
// @lc code=end

