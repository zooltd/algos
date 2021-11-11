/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    int count[1001]{0};
    for (int i = 0; i < arr1.size(); i++)
      count[arr1[i]]++;
    vector<int> ans(arr1.size());
    int n = 0;
    for (int i = 0; i < arr2.size(); i++) {
      while (count[arr2[i]] > 0) {
        count[arr2[i]]--;
        ans[n] = arr2[i];
        n++;
      }
    }

    for (int val = 0; val <= 1000; val++) {
      while (count[val] > 0) {
        count[val]--;
        ans[n] = val;
        n++;
      }
    }

    return ans;
  }
};
// @lc code=end
