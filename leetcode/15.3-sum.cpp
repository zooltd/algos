/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            for (auto vec : twoSums(nums, i + 1, nums.size() - 1, -nums[i]))
                res.push_back({nums[i], vec[0], vec[1]});
        }
        return res;
    }
private:
    vector<vector<int>> twoSums(vector<int>& nums, int l, int r, int target) {
        vector<vector<int>> res;
        for (int i = l, j = r; i < nums.size() - 1; i++) {
            if (i - 1 >= l && nums[i] == nums[i - 1]) continue;
            while (i < j && nums[i] + nums[j] > target) j--;
            if (i < j && nums[i] + nums[j] == target) 
                res.push_back({nums[i], nums[j]});
        }
        return res;
    }
};
// @lc code=end

