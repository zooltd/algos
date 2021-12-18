#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> f(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1)
          f[i][j] = 0;
        else if (i == 0 && j == 0)
          f[i][j] = 1;
        else if (i == 0)
          f[i][j] = f[i][j - 1];
        else if (j == 0)
          f[i][j] = f[i - 1][j];
        else
          f[i][j] = f[i][j - 1] + f[i - 1][j];
      }
    }
    return f[m - 1][n - 1];
  }
};
// @lc code=end
