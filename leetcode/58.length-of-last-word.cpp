/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ed = s.size() - 1;
        for (; ed >= 0; ed--)
            if (s[ed] != ' ') break;
        int st = ed;
        for (; st >= 0; st--)
            if (s[st] == ' ') break;
        return ed - st;
    }
};
// @lc code=end

