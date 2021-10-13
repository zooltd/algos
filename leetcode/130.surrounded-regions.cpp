#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
  void solve(vector<vector<char>> &board) {
    this->m = board.size();
    this->n = board[0].size();
    /* for each 'O' in the border, perform bfs */
    for (int col = 0; col < n; col++) {
      if (board[0][col] == 'O')
        bfs(board, 0, col);
      if (board[m - 1][col] == 'O')
        bfs(board, m - 1, col);
    }
    for (int row = 0; row < m; row++) {
      if (board[row][0] == 'O')
        bfs(board, row, 0);
      if (board[row][n - 1] == 'O')
        bfs(board, row, n - 1);
    }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (board[i][j] == 'O')
          board[i][j] = 'X';
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (board[i][j] == '-')
          board[i][j] = 'O';
  }

private:
  void bfs(vector<vector<char>> &board, int sx, int sy) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    board[sx][sy] = '-';
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
          continue;
        if (board[nx][ny] == 'O') {
          q.push(make_pair(nx, ny));
          board[nx][ny] = '-';
          cnt++;
        }
      }
    }
  }

private:
  int m;
  int n;
  const int dx[4] = {-1, 0, 0, 1};
  const int dy[4] = {0, -1, 1, 0};
};
// @lc code=end
