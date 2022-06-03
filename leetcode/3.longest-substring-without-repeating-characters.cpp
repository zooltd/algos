/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int sz = s.size();
        for (int i = 0, j = 0; i < sz && j < sz; i++) {
            if (i >= 1) us.erase(s[i - 1]);
            while (j < sz && us.find(s[j]) == us.end()) us.insert(s[j++]);
            res = max(res, j - i);
        }
        return res;
    }
private:
    unordered_set<char> us;
};
// @lc code=end

