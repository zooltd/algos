#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    prices.insert(prices.begin(), 0);
    /**
     * f[i, j, k]
     * i: end in i-th day
     * j: hold j(0 or 1) stock
     * k: have k(0 or 1 or 2) transactions
     */
    vector<vector<vector<int>>> f(n + 1,
                                  vector<vector<int>>(2, vector<int>(3, -1e5)));

    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 1; j++)
        for (int k = 0; k <= 2; k++) {
          f[i][j][k] = f[i - 1][j][k];
          if (j == 0)
            f[i][0][k] = max(f[i][0][k], f[i - 1][1][k] + prices[i]);
          if (j == 1 && k > 0)
            f[i][1][k] = max(f[i][1][k], f[i - 1][0][k - 1] - prices[i]);
        }

    int ans = *max_element(f[n][0].begin(), f[n][0].end());
    return ans;
  }
};
// @lc code=end
