#include <vector>
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
      const int INF = 0x3f3f3f3f;
      int n = coins.size();
      coins.insert(coins.begin(), 0);
      vector<int> f(amount + 1, INF);
      f[0] = 0;
      for (int i = 1; i <= n; i++)
          for (int j = coins[i]; j <= amount; j++)
             f[j] = min(f[j], f[j - coins[i]] + 1);
      return f[amount] == INF ? -1 : f[amount];
  }
};
// @lc code=end
