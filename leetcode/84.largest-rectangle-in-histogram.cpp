#include <vector>
#include <stack>
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
      heights.insert(heights.begin(), 0);
      heights.push_back(0);
      stack<int> stk;
      int res = 0;
      for (int i = 0; i < heights.size(); i++) {
        while (stk.size() && heights[stk.top()] > heights[i]) {
          int mid = stk.top();
          stk.pop();
          int l = stk.top();
          int r = i;
          res = max(res, heights[mid] * (r - l - 1));
        }
        stk.push(i);
      }
      return res;
    }
};

// @lc code=end
