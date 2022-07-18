/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n + 1);
        int f0 = 0, f1 = 0, f2;
        for (int i = 2; i <= n; i++) {
            f2 = min(f1 + cost[i - 1], f0 + cost[i - 2]);
            f0 = f1, f1 = f2;
        }
        return f2;
    }
};

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n + 1);
        f[0] = 0;
        f[1] = 0;
        for (int i = 2; i <= n; i++)
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        return f[n];
    }
};
// @lc code=end

