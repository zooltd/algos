#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    this->n = n;
    col_used = vector<bool>(n, false);
    dfs(0);

    vector<vector<string>> result;
    for (vector<int> &per : ans) {
      vector<string> res;
      for (int row = 0; row < n; row++) {
        string s(n, '.');
        int col = per[row];
        s[col] = 'Q';
        res.push_back(s);
      }
      result.push_back(res);
    }
    return result;
  }

private:
  int n;
  vector<int> s;
  vector<vector<int>> ans;
  vector<bool> col_used;
  unordered_map<int, bool> diag_upright_to_downleft_used;
  unordered_map<int, bool> diag_upleft_to_downright_used;

  void dfs(int row) {
    if (row == n) {
      ans.push_back(s);
      return;
    }
    for (int col = 0; col < n; col++)
      /* is valid: 1) check col 2) check diag / 3) check diag \ */
      if (!col_used[col] && !diag_upright_to_downleft_used[row + col] &&
          !diag_upleft_to_downright_used[row - col]) {
        col_used[col] = true;
        diag_upright_to_downleft_used[row + col] = true;
        diag_upleft_to_downright_used[row - col] = true;
        s.push_back(col);
        dfs(row + 1);
        s.pop_back();
        diag_upleft_to_downright_used[row - col] = false;
        diag_upright_to_downleft_used[row + col] = false;
        col_used[col] = false;
      }
  }
};
// @lc code=end
