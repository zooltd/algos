/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (auto x : nums)
            if (k < 2 || nums[k - 2] != x)
                nums[k++] = x;
        return k;
    }
};
// @lc code=end

