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
      stack<int> st;
      int res = 0;
      heights.insert(heights.begin(), 0);
      heights.push_back(0);

      for (int i = 0; i < heights.size(); i++) {
        while (st.size() && heights[st.top()] > heights[i]) {
          int curr = st.top();
          st.pop();
          res = max(res, heights[curr] * (i - st.top() - 1));
        }
        st.push(i);
      }
      return res;
    }
};

// @lc code=end
