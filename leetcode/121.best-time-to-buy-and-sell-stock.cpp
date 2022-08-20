#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min = 0x3f3f3f3f;
        int ans = 0;
        for (int price : prices) {
            min = std::min(min, price);
            ans = std::max(ans, price - min);
        }
        return ans;
    }
};
// @lc code=end

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n, 0);
        // f[i]: sell at day i
        for (int i = 1; i < n; i++)
            f[i] = max(f[i], f[i - 1] + prices[i] - prices[i - 1]);
        return *max_element(f.begin(), f.end());
    }
};

class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // f[i][0]: sell at day i
        // f[i][1]: hold at day i
        vector<vector<int>> f(n, vector<int>(2, 0));
        f[0][0] = 0, f[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i]);
            f[i][1] = max(f[i - 1][1], -prices[i]);
        }
        return f[n - 1][0];
    }
};

// dp with optimized space
class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // f[0]: sell at day i
        // f[1]: hold at day i
        vector<int> f(2, 0);
        f[0] = 0, f[1] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[0] = max(f[0], f[1] + prices[i]);
            f[1] = max(f[1], -prices[i]);
        }
        return f[0];
    }
};