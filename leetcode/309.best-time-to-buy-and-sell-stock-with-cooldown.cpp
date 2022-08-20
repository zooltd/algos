#include <vector>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(2, -0x3f3f3f3f)));
        /**
         * f[i][j][k]: max profit at day i, with j(0/1) stock, in k(0/1) cooldown state
         * in day i:
         * 1. buy:  f[i][1][0] = f[i][0][0] - prices[i]
         * 2. sell: f[i][0][1] = f[i - 1][1][0] + prices[i]
         * 3. n/a:  f[i][j][0] = f[i - 1][j][k]
         */
         f[0][0][0] = 0;

         for (int i = 1; i <= n; i++) {
            f[i][0][0] =  max(f[i - 1][0][0], f[i - 1][0][1]);
            f[i][1][0] = max(f[i - 1][1][0], f[i - 1][0][0] - prices[i]);
            f[i][0][1] = f[i - 1][1][0] + prices[i];
         }
         return max({f[n][0][0], f[n][0][1], f[n][1][0]});
        
    }
};
// @lc code=end

/**
 * @brief also think of the FSM
 * 0,0 represents for cooldown state
 * 1,0 represents for buy in state
 * 0,1 represents for sell out state
 * https://www.acwing.com/video/1699/
 */
 /*
                             0
      ┌─────────────────────────────────────────────┐
      │                                             │
      │                                             │
      ▼                                             │
┌───────────┐            ┌────────────┐       ┌─────┴──────┐
│           │   -p[i]    |            │+p[i]  │            │
│  cooldown ├───────────►┐  buy in    ├──────►│  sell out  │
│    0,0    │            │    1,0     │       │    0,1     │
└──┬────────┘            └───┬────────┘       └────────────┘
   │    ▲                    │    ▲
   │ 0  │                    │ 0  │
   └────┘                    └────┘
 */