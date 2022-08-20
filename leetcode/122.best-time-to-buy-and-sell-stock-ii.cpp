#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    /**
    * @brief https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/
    */
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
            ans += max(0, prices[i] - prices[i - 1]);
        return ans;
    }
};
// @lc code=end

// dp
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // f[i][0]: sell stock at day i
        // f[i][1]: hold stock at day i
        vector<vector<int>> f(n, vector<int>(2, 0));
        f[0][0] = 0, f[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i]);
        }
        return f[n - 1][0];
    }
};

// dp with optimized space
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(2, 0);
        f[0] = 0, f[1] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[0] = max(f[0], f[1] + prices[i]);
            f[1] = max(f[1], f[0] - prices[i]);
        }
        return f[0];
    }
};