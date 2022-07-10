/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> f(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!i && !j) f[j] = grid[i][j];
                else if (!i) f[j] = f[j - 1] + grid[i][j];
                else if (!j) f[j] += grid[i][j];
                else f[j] = min(f[j], f[j - 1]) + grid[i][j];
                
        return f[n - 1];
    }
};
// @lc code=end

