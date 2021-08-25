#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
  int trap(vector<int> &height) {
    int ans = 0;
    stack<int> s;
    for (int i = 0; i < height.size(); i++) {
      while (!s.empty() && height[s.top()] < height[i]) {
        int h = height[s.top()];
        s.pop();
        if (s.empty())
          break;
        int l = s.top();
        int r = i;
        int l_h = height[s.top()];
        int r_h = height[i];
        ans += (min(l_h, r_h) - h) * (r - l - 1);
      }
      s.push(i);
    }
    return ans;
  }
};
// @lc code=end
