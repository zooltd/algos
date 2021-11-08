/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    assert(piles.size() <= h);
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    if (h == piles.size())
      return right;
    int mid;
    while (left < right) {
      mid = (left + right) / 2;
      if (isValid(piles, h, mid))
        right = mid;
      else
        left = mid + 1;
    }
    return right;
  }

private:
  bool isValid(vector<int> &piles, int h, int T) {
    int hrs = 0;
    for (int pile : piles) {
      if (pile % T == 0)
        hrs += pile / T;
      else
        hrs += (pile / T + 1);
    }
    return h >= hrs;
  }
};
// @lc code=end
