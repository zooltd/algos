/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    prices.insert(prices.begin(), 0);

    vector<vector<int>> f(n + 1, vector<int>(2, -1e5));
    f[0][0] = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j <= 1; j++) {
        if (j == 0)
          f[i + 1][1] = max(f[i + 1][1], f[i][j] - prices[i + 1] - fee);
        if (j == 1)
          f[i + 1][0] = max(f[i + 1][0], f[i][j] + prices[i + 1]);
        f[i + 1][j] = max(f[i + 1][j], f[i][j]);
      }

    return f[n][0];
  }
};
// @lc code=end
