/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) { return maxProfit(prices, 0); }

  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    prices.insert(prices.begin(), 0);

    vector<vector<vector<int>>> f(
        n + 1, vector<vector<int>>(2, vector<int>(2, -1e5)));
    f[0][0][0] = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j <= 1; j++)
        for (int l = 0; l <= 1; l++) {
          if (j == 0 && l == 0)
            f[i + 1][1][0] =
                max(f[i + 1][1][0], f[i][j][l] - prices[i + 1] - fee);
          if (j == 1 && l == 0)
            f[i + 1][0][1] = max(f[i + 1][0][1], f[i][j][l] + prices[i + 1]);
          f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][l]);
        }

    int ans = *max_element(f[n][0].begin(), f[n][0].end());
    return ans;
  }
};
// @lc code=end
