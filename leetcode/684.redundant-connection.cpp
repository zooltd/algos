#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    for (vector<int> &e : edges) {
      int u = e[0], v = e[1];
      n = max(n, u);
      n = max(n, v);
    }
    edge = vector<vector<int>>(n + 1, vector<int>());
    visit = vector<bool>(n + 1, false);
    hasCycle = false;
    for (vector<int> &e : edges) {
      int u = e[0], v = e[1];
      addEdge(u, v);
      addEdge(v, u);
      /* Each time add a new edge, to see if there's a cycle. */
      dfs(u, 0);
      if (hasCycle)
        return e;
    }
    return {};
  }

private:
  /* To find a cycle. */
  void dfs(int x, int fa) {
    visit[x] = true;
    for (int y : edge[x]) {
      if (y == fa)
        continue;
      if (!visit[y])
        dfs(y, x);
      else
        hasCycle = true;
    }
    visit[x] = false;
  }

  void addEdge(int x, int y) { edge[x].push_back(y); }

  int n;
  vector<vector<int>> edge;
  vector<bool> visit;
  bool hasCycle;
};
// @lc code=end
