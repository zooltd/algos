/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        dfs(board, x, y);
        return board;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] != 'E') return;
        int sum = 0;
        for (int i = max(0, x - 1); i <= min(m - 1, x + 1); i++)
            for (int j = max(0, y - 1); j <= min(n - 1, y + 1); j++) {
                if (i == x && j == y) continue;
                if (board[i][j] == 'X' || board[i][j] == 'M') sum++;
            }
        
        if (sum) {
            board[x][y] = '0' + sum;
            return;
        }
        board[x][y] = 'B';
        for (int i = max(0, x - 1); i <= min(m - 1, x + 1); i++)
            for (int j = max(0, y - 1); j <= min(n - 1, y + 1); j++) {
                if (i == x && j == y) continue;
                dfs(board, i, j);
            }
    }
private:
    int m;
    int n;
};
// @lc code=end

