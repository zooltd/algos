#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        for (int i = 1; i < n; i++)
            f[i] = max(nums[i], f[i - 1] + nums[i]);
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end

// dp + space opt
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int f = nums[0];
        int res = f;
        for (int i = 1; i < n; i++) {
            f = max(nums[i], f + nums[i]);
            res = max(res, f);
        }
        return res;
    }
};

// divide and conquer, O(nlogn)
class Solution3 {
public:
    int maxSubArray(vector<int> &nums) {
        return divide(nums, 0, nums.size() - 1);
    }

    int divide(vector<int> &nums, int l, int r) {
        if (l == r) return nums[l];
        int mid = (l + r) >> 1;
        int l_ans = divide(nums, l, mid);
        int r_ans = divide(nums, mid + 1, r);
        int res = max(l_ans, r_ans);
        // max sum ending with mid
        int l_sum = 0, l_max = nums[mid];
        // max sum staring from mid + 1
        int r_sum = 0, r_max = nums[mid + 1];
        for (int i = mid; i >= l; i--) {
            l_sum += nums[i];
            l_max = max(l_max, l_sum);
        }
        for (int i = mid + 1; i <= r; i++) {
            r_sum += nums[i];
            r_max = max(r_max, r_sum);
        }
        res = max(res, l_max + r_max);
        return res;
    }
};

// optimize for Solution3, O(n), Segment tree?
// https://www.acwing.com/solution/content/133/
// https://www.acwing.com/solution/content/60882/
class Solution4 {
public:
    // for a range [l~r], maintain a stats
    struct stat {
        // range sum
        int sum;
        // max subarray sum
        int s;
        // max subarray sum starting with l
        int ls;
        // max subarray sum ending with r
        int rs;
    };

    stat build(vector<int> &nums, int l, int r) {
        if (l == r) return {nums[l], nums[l], nums[l], nums[l]};
        int mid = (l + r) >> 1;
        auto L = build(nums, l, mid), R = build(nums, mid + 1, r);
        stat LR{};
        LR.sum = L.sum + R.sum;
        LR.s = max({L.s, R.s, L.rs + R.ls});
        LR.ls = max(L.ls, L.sum + R.ls);
        LR.rs = max(R.rs, R.sum + L.rs);
        return LR;
    }

    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        auto res = build(nums, 0, n - 1);
        return res.s;
    }
};