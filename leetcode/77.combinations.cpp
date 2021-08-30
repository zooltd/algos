#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    this->n = n;
    this->k = k;
    doCombinations(1);
    return ans;
  }

  void doCombinations(int index) {
    if (s.size() > k || s.size() + n - index + 1 < k)
      return;

    if (index > n) {
      ans.push_back(s);
      return;
    }

    // no
    doCombinations(index + 1);

    // yes
    s.push_back(index);
    doCombinations(index + 1);
    s.pop_back();
  }

private:
  vector<vector<int>> ans;
  vector<int> s;
  int n;
  int k;
};

// @lc code=end
