/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool sub[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int t = board[i][j] - '1';
                int k = i / 3 * 3 + j / 3;
                if (rows[i][t] || cols[j][t] || sub[k][t]) return false;
                rows[i][t] = cols[j][t] = sub[k][t] = true;
            }
        }
        return true;
    }
};
// @lc code=end

