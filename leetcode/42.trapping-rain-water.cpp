#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        height.insert(height.begin(), 0);
        for (int i = 0; i < height.size(); i++) {
            while (stk.size() && height[stk.top()] < height[i]) {
                int mid = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int l = stk.top();
                int r = i;
                ans += (min(height[l],height[r]) - height[mid]) * (r - l - 1);
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

