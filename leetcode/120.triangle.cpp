#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> f(2, vector<int>(n, 0));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++)
      for (int j = 0; j <= i; j++)
        if (j == 0) f[i & 1][j] = f[i - 1 & 1][j] + triangle[i][j];
        else if (j == i) f[i & 1][j] = f[i - 1 & 1][j - 1] + triangle[i][j];
        else f[i & 1][j] = min(f[i - 1 & 1][j - 1], f[i - 1 & 1][j]) + triangle[i][j];
    
    return *min_element(f[n - 1 & 1].begin(), f[n - 1 & 1].end());
  }
/**
 * 
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> f(n, vector<int>(n, 0));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++)
      for (int j = 0; j <= i; j++)
        if (j == 0) f[i][j] = f[i - 1][j] + triangle[i][j];
        else if (j == i) f[i][j] = f[i - 1][j - 1] + triangle[i][j];
        else f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
    
    return *min_element(f[n - 1].begin(), f[n - 1].end());
  }
 * 
 */
};
// @lc code=end
