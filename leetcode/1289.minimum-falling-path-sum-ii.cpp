/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> f(m, vector<int>(n, INT_MAX));

    int first_min, second_min;
    first_min = second_min = -1;

    for (int j = 0; j < n; j++) {
      f[0][j] = grid[0][j];
      if (grid[0][j] < (first_min == -1 ? INT_MAX : f[0][first_min])) {
        second_min = first_min;
        first_min = j;
      } else if (grid[0][j] < (second_min == -1 ? INT_MAX : f[0][second_min]))
        second_min = j;
    }

    for (int i = 1; i < m; i++) {
      int new_first_min = -1, new_second_min = -1;
      for (int j = 0; j < n; j++) {
        if (j != first_min)
          f[i][j] = f[i - 1][first_min] + grid[i][j];
        else
          f[i][j] = f[i - 1][second_min] + grid[i][j];
        if (f[i][j] < (new_first_min == -1 ? INT_MAX : f[i][new_first_min])) {
          new_second_min = new_first_min;
          new_first_min = j;
        } else if (f[i][j] < (new_second_min == -1 ? INT_MAX : f[i][new_second_min]))
          new_second_min = j;
      }
      first_min = new_first_min, second_min = new_second_min;
    }
    return *min_element(f[m - 1].begin(), f[m - 1].end());
  }

/**
 * 
  int minFallingPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> f(m, vector<int>(n, INT_MAX));

    int first_min, second_min;
    first_min = second_min = -1;

    for (int j = 0; j < n; j++) {
      f[0][j] = grid[0][j];
      if (grid[0][j] < (first_min == -1 ? INT_MAX : f[0][first_min])) {
        second_min = first_min;
        first_min = j;
      } else if (grid[0][j] < (second_min == -1 ? INT_MAX : f[0][second_min]))
        second_min = j;
    }

    for (int i = 1; i < m; i++) {
      int new_first_min = -1, new_second_min = -1;
      for (int j = 0; j < n; j++) {
        if (j != first_min)
          f[i][j] = f[i - 1][first_min] + grid[i][j];
        else
          f[i][j] = f[i - 1][second_min] + grid[i][j];
        if (f[i][j] < (new_first_min == -1 ? INT_MAX : f[i][new_first_min])) {
          new_second_min = new_first_min;
          new_first_min = j;
        } else if (f[i][j] < (new_second_min == -1 ? INT_MAX : f[i][new_second_min]))
          new_second_min = j;
      }
      first_min = new_first_min, second_min = new_second_min;
    }
    return *min_element(f[m - 1].begin(), f[m - 1].end());
  }
 * 
 */
};
// @lc code=end
