/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && temperatures[stk.top()] <= temperatures[i])
                stk.pop();
            if (stk.empty()) res[i] = 0;
            else res[i] = stk.top() - i;
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

