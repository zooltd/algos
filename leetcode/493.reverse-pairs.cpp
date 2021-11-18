/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
  int reversePairs(vector<int> &nums) {
    ans = 0;
    mergeSort(nums, 0, nums.size() - 1);
    return ans;
  }

  void mergeSort(vector<int> &nums, int l, int r) {
    if (l >= r)
      return;
    int mid = (l + r) >> 1;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    calculate(nums, l, mid, r);
    merge(nums, l, mid, r);
  }

  void calculate(vector<int> &nums, int left, int mid, int right) {
    for (int i = left, j = mid; i <= mid; i++) {
      while (j < right && nums[i] > 2L * nums[j + 1])
        j++;
      ans += j - mid;
    }
  }

  void merge(vector<int> &nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1;

    for (int k = 0; k < temp.size(); k++) {
      if (j > right || (i <= mid && nums[i] <= nums[j]))
        temp[k] = nums[i++];
      else
        temp[k] = nums[j++];
    }

    for (int k = 0; k < temp.size(); k++) {
      nums[left + k] = temp[k];
    }
  }

private:
  int ans;
};
// @lc code=end
