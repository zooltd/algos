#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> PII;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<PII> nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = {points[i][0] * points[i][0] + points[i][1] * points[i][1], i};
        quick_select(nums, 0, n - 1, k);
        vector<vector<int>> res(k);
        for (int i = 0; i < k; i++)
            res[i] = points[nums[i].second];
        return res;
    }

    void quick_select(vector<PII>& nums, int l, int r, int k) {
        if (l >= r) return;
        int i = l - 1, j = r + 1;
        int x = nums[(l + r) >> 1].first;
        while (i < j) {
            do i++; while (nums[i].first < x);
            do j--; while (nums[j].first > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (j - l + 1 >= k) quick_select(nums, l, j, k);
        else quick_select(nums, j + 1, r, k - (j - l + 1));
    }
};

class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k - 1, points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
// @lc code=end

