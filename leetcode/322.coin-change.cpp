#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int INF = 1e9;
    vector<int> opts(amount + 1, INF);
    opts[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (i - coins[j] >= 0)
          opts[i] = min(opts[i], opts[i - coins[j]] + 1);
      }
    }
    if (opts[amount] >= INF)
      opts[amount] = -1;
    return opts[amount];
  }
};
// @lc code=end
