/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
        }
        return i + 1;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
       return unique(nums.begin(), nums.end()) -  nums.begin();
    }
};
// @lc code=end

