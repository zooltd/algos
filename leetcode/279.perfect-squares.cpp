/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> candidates;
        for (int i = 1; i * i <= n; i++) candidates.push_back(i * i);
        int sz = candidates.size();

        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 0; i < sz; i++)
            for (int j = candidates[i]; j <= n; j++)
                f[j] = min(f[j], f[j - candidates[i]] + 1);
        return f[n];
    }
};
// @lc code=end

