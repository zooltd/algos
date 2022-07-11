/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(2, vector<int>(n, 0));
        for (int j = 0; j < n; j++) f[0][j] = matrix[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (j == 0) f[i & 1][j] = min(f[i - 1 & 1][j], f[i - 1 & 1][j + 1]) + matrix[i][j];
                else if (j == n - 1) f[i & 1][j] = min(f[i - 1 & 1][j], f[i - 1 & 1][j - 1]) + matrix[i][j];
                else f[i & 1][j] = min(min(f[i - 1 & 1][j - 1], f[i - 1 & 1][j]), f[i - 1 & 1][j + 1]) + matrix[i][j];
            }
        return *min_element(f[m - 1 & 1].begin(), f[m - 1 & 1].end());
    }

/**
 * 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) f[0][j] = matrix[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (j == 0) f[i][j] = min(f[i - 1][j], f[i - 1][j + 1]) + matrix[i][j];
                else if (j == n - 1) f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + matrix[i][j];
                else f[i][j] = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i - 1][j + 1]) + matrix[i][j];
            }
        return *min_element(f[m - 1].begin(), f[m - 1].end());
    }
 * 
 */
};
// @lc code=end

