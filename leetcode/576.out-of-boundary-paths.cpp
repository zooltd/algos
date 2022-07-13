#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        vector<vector<vector<int>>> f(m + 2, vector<vector<int>>(n + 2, vector<int>(maxMove + 1, 0)));
        
        for (int col = 0; col < n + 2; col++)
            for (int k = 0; k <= maxMove; k++)
                f[0][col][k] = f[m + 1][col][k] = 1;
        
       for (int row = 0; row < m + 2; row++)
            for (int k = 0; k <= maxMove; k++)
                f[row][0][k] = f[row][n + 1][k] = 1; 
        
        for (int k = 1; k <= maxMove; k++)
            for (int x = 1; x < m + 1; x++)
                for (int y = 1; y < n + 1; y++) {
                    int sum = 0;
                    for (int i = 0; i < 4; i++) {
                        sum += f[x + dx[i]][y + dy[i]][k - 1];
                        sum %= MOD;
                    }
                    f[x][y][k] = sum;
                }
                
        return f[startRow + 1][startColumn + 1][maxMove];
    }
};

class Solution2 {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        cache.resize(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(m, n, maxMove, startRow, startColumn);
    }

    int dfs(int m, int n, int maxMove, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) return 1;

        if (maxMove == 0) return 0;

        if (cache[x][y][maxMove] != -1) return cache[x][y][maxMove];

        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += dfs(m, n, maxMove - 1, x + dx[i], y + dy[i]);
            sum %= MOD;
        }
        
        cache[x][y][maxMove] = sum;
        return sum;
    }

private:
    const int MOD = 1e9 + 7;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<vector<int>>> cache;
};
// @lc code=end

