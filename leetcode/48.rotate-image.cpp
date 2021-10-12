#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int start = 0, end = n - 1;
    while (start < end) {
      /* rotate ring [start, end] */
      int p1 = start;
      int p2 = end;
      while (p1 != end) {
        int temp = matrix[start][p1];
        matrix[start][p1] = matrix[p2][start];
        matrix[p2][start] = matrix[end][p2];
        matrix[end][p2] = matrix[p1][end];
        matrix[p1][end] = temp;
        p1 += 1;
        p2 -= 1;
      }

      start++;
      end--;
    }
  }
};
// @lc code=end
