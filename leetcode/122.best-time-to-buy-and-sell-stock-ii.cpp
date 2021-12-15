/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); i++) {
      int gap = prices[i] - prices[i - 1];
      if (gap > 0)
        ans += gap;
    }
    return ans;
  }
};
// @lc code=end
