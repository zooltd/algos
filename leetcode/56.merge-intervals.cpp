#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    /* diff */
    vector<pair<int, int>> events;
    for (vector<int> &vec : intervals) {
      events.push_back(make_pair(vec[0], 1));
      events.push_back(make_pair(vec[1] + 1, -1));
    }
    sort(events.begin(), events.end());
    vector<vector<int>> ans;
    int left;
    int cnt = 0;
    for (pair<int, int> &event : events) {
      if (cnt == 0)
        left = event.first;
      cnt += event.second;
      if (cnt == 0)
        ans.push_back({left, event.first - 1});
    }
    return ans;
  }
};
// @lc code=end
