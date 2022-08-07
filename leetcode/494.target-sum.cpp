#include <numeric>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
/**
 * 
f[i][j] = f[i - 1][j - nums[i]] + f[i - 1][j + nums[i]]
 * 
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        vector<vector<int>> f(n + 1, vector<int>(2 * sum + 1, 0));
        f[0][0 + sum] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= 2 * sum; j++) {
                if (j - nums[i - 1] >= 0)
                    f[i][j] += f[i - 1][j - nums[i - 1]];
                if (j + nums[i - 1] <= 2 * sum)
                    f[i][j] += f[i - 1][j + nums[i - 1]];
            }
        return f[n][target + sum];
    }
};
// @lc code=end

