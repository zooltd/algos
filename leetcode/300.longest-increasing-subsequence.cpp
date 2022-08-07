#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
              if (nums[j] < nums[i])
                f[i] = max(f[i], f[j] + 1);
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end
