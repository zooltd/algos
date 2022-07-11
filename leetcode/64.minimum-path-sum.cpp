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
                if (i > 0 && j > 0) f[j] = min(f[j], f[j - 1]) + grid[i][j];
                else if (i > 0) f[j] = f[j] + grid[i][j];
                else if (j > 0) f[j] = f[j - 1] + grid[i][j];
                else f[j] = grid[i][j];
        return f[n - 1];
    }

/**
 *
    int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> f(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i > 0 && j > 0) f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            else if (i > 0) f[i][j] = f[i - 1][j] + grid[i][j];
            else if (j > 0) f[i][j] = f[i][j - 1] + grid[i][j];
            else f[i][j] = grid[i][j];
    return f[m - 1][n - 1];
    }
 * 
 */
};
// @lc code=end

