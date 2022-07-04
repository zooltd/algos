/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int num : s) {
            if (s.find(num - 1) != s.end()) continue;
            // num is the starting point of a sequence
            int end = num + 1;
            while (s.find(end) != s.end())
                end++;
            res = max(end - num, res);
        }
        return res;
    }
};
// @lc code=end

