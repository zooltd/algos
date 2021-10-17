#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size();
    n = matrix[0].size();
    edges = vector<vector<int>>(m * n, vector<int>());
    inDeg = vector<int>(m * n, 0);
    distTo = vector<int>(m * n, 0);
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        bool flag = true;
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (valid(ni, nj) && matrix[i][j] < matrix[ni][nj]) {
            addEdge(num(i, j), num(ni, nj));
          }
        }
      }
    topsort();
    int ans = 0;
    for (int i = 0; i < m * n; i++)
      ans = max(ans, distTo[i]);
    return ans;
  }

private:
  void topsort() {
    queue<int> q;
    for (int i = 0; i < m * n; i++)
      if (inDeg[i] == 0)
        q.push(i), distTo[i] = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : edges[x]) {
        inDeg[y]--;
        distTo[y] = max(distTo[y], distTo[x] + 1);
        if (inDeg[y] == 0) {
          q.push(y);
        }
      }
    }
  }

  void addEdge(int u, int v) {
    edges[u].push_back(v);
    inDeg[v]++;
  }
  int valid(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }
  int num(int i, int j) { return i * n + j; }
  int m;
  int n;
  vector<vector<int>> edges;
  vector<int> inDeg;
  vector<int> distTo;
};

/* dfs + memorize
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size();
    n = matrix[0].size();
    answer = vector<vector<int>>(m, vector<int>(n, -1));
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans = max(ans, howfar(matrix, i, j));
      }
    }
    return ans;
  }

private:
  int howfar(vector<vector<int>> &matrix, int x, int y) {
    if (answer[x][y] != -1)
      return answer[x][y];
    answer[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= m || ny >= n)
        continue;
      if (matrix[nx][ny] > matrix[x][y]) {
        answer[x][y] = max(answer[x][y], howfar(matrix, nx, ny) + 1);
      }
    }
    return answer[x][y];
  }

private:
  int m;
  int n;
  vector<vector<int>> answer;
  const int dx[4] = {-1, 0, 0, 1};
  const int dy[4] = {0, -1, 1, 0};
};*/
// @lc code=end
