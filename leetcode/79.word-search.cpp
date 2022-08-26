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
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, const string& word, int x, int y, int idx) {
        const static int dx[4] = {-1, 0, 1, 0};
        const static int dy[4] = {0, 1, 0, -1};
        
        if (board[x][y] != word[idx]) return false;
        if (idx == word.size() - 1) return true;
        char tmp = board[x][y];
        board[x][y] = '.';
        
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n || board[a][b] == '.') continue;
            if (dfs(board, word, a, b, idx + 1)) return true;
        }

        board[x][y] = tmp;
        return false;
    }
private:
    int m, n;
};
// @lc code=end
