#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
public:
  int minMutation(string start, string end, vector<string> &bank) {
    unordered_set<string> bankSet(bank.begin(), bank.end());
    const char gene[4] = {'A', 'C', 'G', 'T'};
    unordered_map<string, int> depth;
    queue<string> q;
    q.push(start);
    depth[start] = 0;
    while (!q.empty()) {
      string s = q.front();
      q.pop();
      /* s[i] -> gene[j] */
      for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++) {
          if (s[i] == gene[j])
            continue;
          string ns = s;
          ns[i] = gene[j];
          /* not in the bank, invalid */
          if (bankSet.find(ns) == bankSet.end())
            continue;
          /* update */
          if (depth.find(ns) == depth.end()) {
            depth[ns] = depth[s] + 1;
            q.push(ns);
            if (ns == end)
              return depth[ns];
          }
        }
    }
    return -1;
  }
};
// @lc code=end
