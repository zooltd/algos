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
    doCombinations(1, n, k);
    this->n = n;
    this->k = k;
    return ans;
  }

  void doCombinations(int index, int n, int k) {
    if (index > n) {
      if (s.size() == k) {
        ans.push_back(s);
        return;
      }
      return;
    }

    // no
    doCombinations(index + 1, n, k);

    // yes
    s.push_back(index);
    doCombinations(index + 1, n, k);
    s.pop_back();
  }

private:
  vector<vector<int>> ans;
  vector<int> s;
  int n;
  int k;
};

// @lc code=end
