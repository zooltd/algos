#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    res = max(res, dfs(grid, i, j));
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        const static int dx[4] = {-1, 0, 1, 0};
        const static int dy[4] = {0, 1, 0, -1}; 
        grid[x][y] = 0;
        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] == 0) continue;
            cnt += dfs(grid, a, b);
        }
        return cnt;
    }
private:
    int m, n;
};
// @lc code=end

