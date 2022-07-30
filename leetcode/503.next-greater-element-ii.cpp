/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        stack<int> stk;
        vector<int> res(n);
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (stk.size() && stk.top() <= nums[i]) stk.pop();
            if (i < n) res[i] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i]);
        }
        return res;
    }
};
// @lc code=end

