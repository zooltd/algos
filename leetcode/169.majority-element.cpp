/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, candidate;
        for (int num : nums) {
            if (cnt == 0) candidate = num, cnt = 1;
            else if (candidate == num) cnt++;
            else cnt--;
        }
        return candidate;
    }
};
// @lc code=end

