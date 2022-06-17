#include <vector>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        this->word = word;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, i, j, 0)) return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, int x, int y, int i) {
        if (board[x][y] != word[i]) return false;
        if (i == word.size() - 1) return true;
        char t = board[x][y];
        board[x][y] = '.';

        for (int d = 0; d < 4; d++) {
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= m || b < 0 || b >= n || board[a][b] == '.') continue;
            if (dfs(board, a, b, i + 1)) return true;
        }
        board[x][y] = t;
        return false;
    }

private:
    int m;
    int n;
    string word;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
};
// @lc code=end
