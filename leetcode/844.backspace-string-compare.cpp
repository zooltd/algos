/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        while (true) {
            int k = 0;
            while (i >= 0 && (k || s[i] == '#')) {
                if (s[i] == '#') k++;
                else k--;
                i--;
            }
            
            k = 0;
            while (j >= 0 && (k || t[j] == '#')) {
                if (t[j] == '#') k++;
                else k--;
                j--;
            }

            if (i >= 0 && j >= 0 && s[i] == t[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }
};
// @lc code=end

