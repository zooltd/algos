#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> mp;
        // <num, idx>
        for (int i = 0; i < n; i++) mp[nums1[i]] = i;
        vector<int> res(n);
        stack<int> stk;
        for (int i = m - 1; i >= 0; i--) {
            if (mp.empty()) break;
            while (stk.size() && stk.top() <= nums2[i]) stk.pop();
            auto iter = mp.find(nums2[i]);
            if (iter != mp.end()) {
                auto idx = (*iter).second;
                if (stk.empty()) res[idx] = -1;
                else res[idx] = stk.top();
                mp.erase(iter);
            }
            stk.push(nums2[i]);
        }
        return res;
    }
};
// @lc code=end

