#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> s;
    int ans = 0;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
      while (!s.empty() && heights[s.top()] > heights[i]) {
        int cur = s.top();
        s.pop();
        int left = s.top() + 1;
        int right = i - 1;
        ans = max(ans, (right - left + 1) * heights[cur]);
      }
      s.push(i);
    }
    return ans;
  }
};

// @lc code=end
