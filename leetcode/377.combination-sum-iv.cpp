#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /**
         * f[i]: # possible combinations for f[i]
         * f[i] = Σ f[i - j], j ∈ nums
         */
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int j : nums)
                if (i >= j)
                    f[i] += f[i - j];
        return f[target];
    }
};
// @lc code=end

