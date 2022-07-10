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

    vector<int> f(n, 0);
    f[0] = 1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (obstacleGrid[i][j] == 1) f[j] = 0;
        else if(j > 0) f[j] += f[j - 1];
    return f[n - 1];
  }

  // int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  //   int m = obstacleGrid.size();
  //   int n = obstacleGrid[0].size();

  //   vector<vector<int>> f(m, vector<int>(n, 0));

  //   for (int i = 0; i < m; i++)
  //     for (int j = 0; j < n; j++)
  //       if (obstacleGrid[i][j] == 0) {
  //         if (!i && !j) f[i][j] = 1;
  //         else {
  //           if (i) f[i][j] += f[i - 1][j];
  //           if (j) f[i][j] += f[i][j - 1];
  //         }
  //       }
  
  //   return f[m - 1][n - 1];
  // }
};
// @lc code=end
