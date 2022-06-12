/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string res;
        for (int i = 0; i < s.size();) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) j++;
            res += to_string(j - i) + s[i];
            i = j;
        }
        return res;
    }
};
// @lc code=end

