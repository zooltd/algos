/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // <diff, value>
        pair<int, int> res(INT_MAX, INT_MAX);
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                // minimum sum that >= target
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target) k--;
                int sum = nums[i] + nums[j] + nums[k];
                res = min(res, make_pair(abs(sum - target), sum));
                // maximum sum that < target
                if (k - 1 > j) {
                    sum = nums[i] + nums[j] + nums[k - 1];
                    res = min(res, make_pair(target - sum, sum));
                }          
            }
        }
        return res.second;
    }
};
// @lc code=end

