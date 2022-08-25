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
        board.resize(n, string(n, '.'));
        cols.resize(n, false);
        diag.resize(2 * n - 1, false);
        udiag.resize(2 * n - 1, false);
        dfs(0, n);
        return res;
    }
    
    void dfs(int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag[row + col] || udiag[row - col + n - 1]) continue;
            cols[col] = diag[row + col] = udiag[row - col + n - 1] = true;
            board[row][col] = 'Q';
            dfs(row + 1, n);
            cols[col] = diag[row + col] = udiag[row - col + n - 1] = false;
            board[row][col] = '.';
        }
    }
private:
    vector<string> board;
    vector<vector<string>> res;
    vector<bool> cols, diag, udiag;
};
// @lc code=end

