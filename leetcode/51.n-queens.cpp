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
        cols = vector<bool>(n, false);
        diags = vector<bool>(2 * n - 1, false);
        udiags = vector<bool>(2 * n - 1, false);
        vector<string> board(n, string(n, '.'));
        dfs(board, n, 0);
        return res;
    }
    
    void dfs(vector<string>& board, int n, int row) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols[col] || diags[row + col] || udiags[row - col + n - 1]) continue;
            
            cols[col] = diags[row + col] = udiags[row - col + n - 1] = true; 

            board[row][col] = 'Q';
            dfs(board, n, row + 1);
            board[row][col] = '.';

            cols[col] = diags[row + col] = udiags[row - col + n - 1] = false; 
        }
    }
private:
    vector<bool> cols, diags, udiags;
    vector<vector<string>> res;
};
// @lc code=end

