#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++)
            if (nums[i] > nums[i - 1])
                f[i] = f[i - 1] + 1;
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end

