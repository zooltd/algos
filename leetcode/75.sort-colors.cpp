/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [0, j - 1]: 0
        // [j, i - 1]: 1
        // [k, n - 1]: 2
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            if (nums[i] == 0) swap(nums[i++], nums[j++]);
            else if (nums[i] == 2) swap(nums[i], nums[k--]);
            else i++;
        }
    }
};
// @lc code=end

