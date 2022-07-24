#include <string>
#include <vector>
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
        vector<string> board(n, string (n, '.'));
        vector<bool> col_used(n, false);
        vector<bool> dg_used(2 * n - 1, false);
        vector<bool> udg_used(2 * n - 1, false);
        dfs(board, n, 0, col_used, dg_used, udg_used);
        return res;
    }

    void dfs(vector<string>& board, int n, int row, vector<bool>& col_used,
            vector<bool>& dg_used, vector<bool>& udg_used) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (col_used[col] || dg_used[col + row] || udg_used[col - row + n - 1]) continue;
            col_used[col] = dg_used[col + row] = udg_used[col - row + n - 1] = true;
            board[row][col] = 'Q';
            dfs(board, n, row + 1, col_used, dg_used, udg_used);
            col_used[col] = dg_used[col + row] = udg_used[col - row + n - 1] = false;
            board[row][col] = '.';
        }
    }

private:
    vector<vector<string>> res;
};
// @lc code=end

