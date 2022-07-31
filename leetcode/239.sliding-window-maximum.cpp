#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        // ↘
        for (int i = 0; i < nums.size(); i++) {
            while (dq.size() && i - dq.front() + 1 > k) dq.pop_front();
            while (dq.size() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
// @lc code=end

