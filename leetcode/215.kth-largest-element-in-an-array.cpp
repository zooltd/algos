/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    return quicksort(nums, nums.size() - k, 0, nums.size() - 1);
  }

  int quicksort(vector<int> &nums, int k, int l, int r) {
    if (l == r)
      return nums[l];
    int p = partition(nums, l, r);
    if (p >= k)
      return quicksort(nums, k, l, p);
    else
      return quicksort(nums, k, p + 1, r);
  }

  int partition(vector<int> &a, int l, int r) {
    int pivot = l + rand() % (r - l + 1);
    int pivotVal = a[pivot];

    while (l <= r) {
      while (a[l] < pivotVal)
        l++;
      while (a[r] > pivotVal)
        r--;
      if (l <= r) {
        swap(a[l], a[r]);
        l++;
        r--;
      }
    }

    return r;
  }
};
// @lc code=end
