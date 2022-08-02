#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int cnt[201] = {0};
        for (const int num : nums) cnt[num + 100]++;
        sort(begin(nums), end(nums), [&](int lhs, int rhs) {
            return cnt[lhs + 100] == cnt[rhs + 100] ? lhs > rhs : cnt[lhs + 100] < cnt[rhs + 100];
        });
        return nums;
    }
};
// @lc code=end

