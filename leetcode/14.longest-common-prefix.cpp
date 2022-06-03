/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) break;
        }
        return prefix;
    }
private:
    string longestCommonPrefix(const string& s1, const string& s2) {
        int i = 0;
        for (; i < s1.size() && i < s2.size(); i++)
            if (s1[i] != s2[i]) break;
        return s1.substr(0, i);
    }
};
// @lc code=end

