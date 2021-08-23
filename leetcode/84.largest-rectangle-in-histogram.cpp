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
    heights.push_back(0);
    stack<Rect> s;
    int ans = 0;
    for (int h : heights) {
      int accumulated_width = 0;
      while (!s.empty() && s.top().height >= h) {
        accumulated_width += s.top().width;
        ans = max(ans, accumulated_width * s.top().height);
        s.pop();
      }
      s.push({h, accumulated_width + 1});
    }
    return ans;
  }

private:
  struct Rect {
    int height;
    int width;
  };
};

// @lc code=end
