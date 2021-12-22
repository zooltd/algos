/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> f(amount + 1, 0);
    f[0] = 1;
    for (int i = 0; i < coins.size(); i++)
      for (int j = coins[i]; j <= amount; j++)
        f[j] += f[j - coins[i]];
    return f[amount];
  }
};
// @lc code=end
