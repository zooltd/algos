#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum / 2;

        vector<int> f(target + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            for (int j = target; j >= nums[i]; j--)
                f[j] = max(f[j], f[j - nums[i]] + nums[i]);
        return f[target] == target; 
    }
};
// @lc code=end
