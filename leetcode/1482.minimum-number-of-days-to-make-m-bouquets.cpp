#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution {
public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int min = bloomDay[0], max = bloomDay[0];
    for (int i = 0; i < bloomDay.size(); i++) {
      min = std::min(min, bloomDay[i]);
      max = std::max(max, bloomDay[i]);
    }
    max++;
    int left = min, right = max;
    int mid;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (isValid(bloomDay, m, k, mid))
        right = mid;
      else
        left = mid + 1;
    }
    return (right == max) ? -1 : right;
  }

private:
  /* is valid on day T */
  bool isValid(vector<int> &bloomDay, int m, int k, int T) {
    int cnt = 0;
    int bouquet = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
      if (bloomDay[i] <= T) {
        cnt++;
        if (cnt == k) {
          bouquet++;
          cnt = 0;
        }
      } else {
        cnt = 0;
      }
    }
    return bouquet >= m;
  }
};
// @lc code=end
