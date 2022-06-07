/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        long long num = 0;
        int n = x;
        while (n) {
            int d = n % 10;
            num = num * 10 + d;
            n /= 10;
        }
        return num == x;   
    }
};
// @lc code=end

