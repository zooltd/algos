#include <vector>
#include <string>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=1301 lang=cpp
 *
 * [1301] Number of Paths with Max Score
 */

// @lc code=start
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<char>> grids(n, vector<char>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grids[i][j] = board[i][j];

        // maximum sum
        vector<vector<int>> f(n, vector<int>(n, -1));
        // count of plans
        vector<vector<int>> g(n, vector<int>(n, 0));

        for (int x = n - 1; x >= 0; x--) {
            for (int y = n - 1; y >= 0; y--) {
                // starting point
                if (x == n - 1 && y == n - 1) {
                    f[x][y] = 0;
                    g[x][y] = 1;
                    continue;
                }

                // obstacle
                if (grids[x][y] == 'X') {
                    f[x][y] = -1;
                    g[x][y] = 0; 
                    continue;
                }

                int val = (x == 0 && y == 0) ? 0 : grids[x][y] - '0';
                
                // ↑, ←, ↖
                int dx[3] = {1, 0, 1};
                int dy[3] = {0, 1, 1};
                vector<int> sums(3, -1);
                for (int i = 0; i < 3; i++) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a < n && b < n && f[a][b] != -1) {
                        sums[i] = (f[a][b] + val) % MOD;
                        f[x][y] = max(sums[i], f[x][y]);
                    }
                }

                for (int i = 0; i < 3; i++)
                    if (sums[i] != -1 && f[x][y] == sums[i]) {
                        g[x][y] += g[x + dx[i]][y + dy[i]];
                        g[x][y] %= MOD;
                    }
            }
        }

        return f[0][0] == -1 ? vector<int>{0, 0} : vector<int>{f[0][0], g[0][0]};
    }
};
// @lc code=end

