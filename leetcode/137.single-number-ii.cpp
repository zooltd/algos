/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
            int sum = 0;
            for (int num : nums) sum += ((num >> i) & 0x1);
            res |= (sum % 3) << i;
        }
        return res;
    }
};
// @lc code=end

