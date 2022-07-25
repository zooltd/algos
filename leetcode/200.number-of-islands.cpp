#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    m = grid.size();
    n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ans++;
        }
    return ans;
  }

private:
  void dfs(vector<vector<char>> &grid, int x, int y) {
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == '0') continue;
      grid[nx][ny] = '0';
      dfs(grid, nx, ny);
    }
  }

private:
  int m;
  int n;
  const int dx[4] = {-1, 0, 0, 1};
  const int dy[4] = {0, -1, 1, 0};
};

// @lc code=end
