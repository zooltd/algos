/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            // [l, mid] is sorted
            if (nums[mid] >= nums[0]) {
                if (nums[0] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } 
            // [mid, r] is sorted
            else {
                if (nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
