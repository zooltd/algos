#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    n = numCourses;
    edge = vector<vector<int>>(n, vector<int>());
    inDeg = vector<int>(n, 0);
    for (vector<int> &p : prerequisites) {
      int ai = p[0], bi = p[1];
      addEdge(ai, bi);
    }
    return topsort();
  }

private:
  /* x->y */
  void addEdge(int x, int y) {
    edge[x].push_back(y);
    inDeg[y]++;
  }

  bool topsort() {
    queue<int> q;
    /* start from vertices with 0 indegree */
    for (int i = 0; i < n; i++) {
      if (inDeg[i] == 0)
        q.push(i);
    }
    int classes = 0;
    /* BFS */
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      classes++;
      for (int y : edge[x]) {
        inDeg[y]--;
        if (inDeg[y] == 0)
          q.push(y);
      }
    }
    return classes == n;
  }

  int n;
  vector<vector<int>> edge;
  vector<int> inDeg;
};
// @lc code=end
