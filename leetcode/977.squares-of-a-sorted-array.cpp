/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int l = 0, r = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = abs(nums[r]) > abs(nums[l]) ?
            nums[r] * nums[r--] : nums[l] * nums[l++];
        }
        return res;
    }
};
// @lc code=end

