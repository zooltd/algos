#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';
                    rows[i][digit] = cols[j][digit] = 
                    grids[i / 3][j / 3][digit] = true;
                }
        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int row, int col) {
        if (col == 9) row++, col = 0;
        if (row == 9) return true;
        if (board[row][col] != '.')
            return dfs(board, row, col + 1);

        for (int i = 0; i < 9; i++) {
            if (rows[row][i] || cols[col][i] || grids[row / 3][col / 3][i]) continue;
            rows[row][i] = cols[col][i] = grids[row / 3][col / 3][i] = true;
            board[row][col] = '1' + i;
            if (dfs(board, row, col + 1)) return true;
            rows[row][i] = cols[col][i] = grids[row / 3][col / 3][i] = false;
            board[row][col] = '.';
        }
        return false;
    }

private:
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool grids[3][3][9] = {false};
};
// @lc code=end

