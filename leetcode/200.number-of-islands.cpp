#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;                    
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        const static int dx[4] = {-1, 0, 1, 0};
        const static int dy[4] = {0, 1, 0, -1}; 
        grid[x][y] = '0';
        
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] == '0') continue;
            dfs(grid, a, b);
        }
    }
private:
    int m, n;
};
// @lc code=end

