/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min = 1e5;
    int ans = 0;
    for (int price : prices) {
      min = std::min(min, price);
      ans = std::max(ans, price - min);
    }
    return ans;
  }
};
// @lc code=end
