#include <vector>
#include <algorithm>
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
        if (n == 0) return 0;
        /**
         * f[i][j][k]
         * i: at day i
         * j: hold j(0/1) stocks
         * k: this is the k-th transaction
         */
        vector<vector<vector<int>>> f(n, vector<vector<int>>(2, vector<int>(3 + 1, -1e5)));

        f[0][0][0] = 0;
        f[0][1][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= 2; k++) {
                f[i][0][k] = f[i - 1][0][k];
                f[i][0][k] = max(f[i][0][k], f[i - 1][1][k] + prices[i]);

                f[i][1][k] = f[i - 1][1][k];
                if (k >= 1) f[i][1][k] = max(f[i][1][k], f[i - 1][0][k - 1] - prices[i]);
            }
        }

        return *max_element(f[n - 1][0].begin(), f[n - 1][0].end());
    }
};
// @lc code=end

class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        prices.insert(prices.begin(), 0);
        /**
         * f[i][j][k]
         * i: at day i
         * j: hold j(0/1) stocks
         * k: this is the k-th transaction
         */
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(3, -1e5)));

        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= 2; k++) {
                f[i][0][k] = f[i - 1][0][k];
                f[i][0][k] = max(f[i][0][k], f[i - 1][1][k] + prices[i]);

                f[i][1][k] = f[i - 1][1][k];
                if (k >= 1) f[i][1][k] = max(f[i][1][k], f[i - 1][0][k - 1] - prices[i]);
            }
        }

        return *max_element(f[n][0].begin(), f[n][0].end());
    }
};