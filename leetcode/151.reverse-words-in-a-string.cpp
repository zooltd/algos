/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        for (int l = 0; l < s.size(); l++) {
            if (s[l] == ' ') continue;

            if (i != 0) s[i++] = ' ';
            
            int r = l;
            while (r < s.size() && s[r] != ' ')
                s[i++] = s[r++];
            reverse(s.begin() + i - r + l, s.begin() + i);

            l = r;
        }
        s.erase(s.begin() + i, s.end());
        return s;
    }
};
// @lc code=end

