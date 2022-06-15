/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 1, x = 0, y = 0, d = 0; i <= n * n; i++) {
            res[x][y] = i;
            visited[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= n || visited[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }

private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
};
// @lc code=end

